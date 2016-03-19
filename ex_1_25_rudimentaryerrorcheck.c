/**
 *	Check a C program for rudimentary syntax errors
 *	like unbalanced parentheses, brackets and braces.
 *	Quotes, both single and double, escape sequence,
 *	and comments.
 */
#include <stdio.h>

main(){
	FILE *f;
	int c;

	int parentheses = 0;
	int brackets = 0;
	int braces = 0;
	int singlequotes = 0;
	int doublequotes = 0;

	/* Get characters from file */
	f = freopen("syntaxcheck.c", "r", stdin);
	while((c = getchar()) != EOF){
		if(c == '(') parentheses++;
		if(c == ')') parentheses--;
		if(c == '[') brackets++;
		if(c == ']') brackets--;
		if(c == '{') braces++;
		if(c == '}') braces--;
		if(c == '\"') singlequotes++;
		if(c == '"') doublequotes++;
		putchar(c);
	}

	printf("\n\nparentheses: %d\nbrackets: %d\nbraces: %d\nsinglequotes: %d\ndoublequotes: %d\n", parentheses, 
		brackets, braces, singlequotes, doublequotes);
	if(!parentheses && !brackets && !braces && 
		singlequotes % 2 == 0 &&
		doublequotes % 2 == 0)printf("No error with the count of symbol");

	fclose(f);
}

