/**
 *	Add modulus (%) operator and provisions for negative numbers
 *	Add commands to print the top element of the stack without popping,
 *	to duplicate it, and to swap the top two elements
 *	Add a command to clear the stack
 *	Add access to library function like sin, exp, and pow
 *	Add commands for handling variables (twenty-six variables with single-letter word)
 *	Add a variable for the most recently printed value
 *	Write a routine ungets(s) that will push back an entire string onto the input
 *	(Suppose that there will never be more than one character of pushback
 * 	. Modifygetch and ungetch accordingly)
 *	Handle a pushed-back EOF correctly
 *	An alternate organization uses getline to read an entire input line; this makes
 *	getch and ungetch unnecessary
 */
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h> /* for atof() */

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXVAL 100
#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */
int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

int getop(char[]);
void print(void);
void duplicate(void);
void swap(void);
void clear(void);
void push(double);
double pop(void);

/* reverse Polish calculator */
int main(){
	int type;
	double op2;
	char s[MAXOP];

	while((type = getop(s)) != EOF){
		switch(type){
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if(op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '%':
			op2 = pop();
			if(op2 != 0.0){
				push((int)pop() % (int)op2);
				printf("note: both side of module is casted to integer\n");
			}
			else
				printf("error: zero module\n");
			break;
		case 'p':
			print();
			break;
		case 'd':
			duplicate();
			break;
		case 's':
			swap();
			break;
		case 'c':
			clear();
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}

void print(void){
	if(sp > 1)
		printf("top two elements: %lf %lf\n", val[sp - 1], val[sp - 2]);
	else if(sp > 0)
		printf("error: only one element left\n");
	else
		printf("error: stack empty\n");
}

void duplicate(){
	if(sp > 0){
		push(val[sp - 1]);
	}else
		printf("error: stack empty\n");
}

void clear(){
	while(sp > 0){
		pop();
	}
}

void swap(){
	if(sp > 1){
		double op1 = pop();
		double op2 = pop();
		push(op1);
		push(op2);
	}
	else if(sp > 0)
		printf("error: only one element left\n");
	else
		printf("error: stack empty\n");
}

/* push: push f onto value stack */
void push(double f){
	if(sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void){
	if(sp > 0)
		return val[--sp];
	else{
		printf("error: stack empty\n");
		return 0.0;
	}
}

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[]){
	int i, c;

	while((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] == '\0';
	if(!isdigit(c) && c != '.')
		return c; /* not a number */
	i = 0;
	if(isdigit(c)) /* collect integer part */
		while(isdigit(s[++i] = c = getch()))
			;
	if(c == '.') /* collect fraction part */
		while(isdigit(s[++i] = c = getch()))
			;
	s[i] == '\0';
	if(c != EOF)
		ungetch(c);
	return NUMBER;
}

int getch(void) /* get a (possibly pushed back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}