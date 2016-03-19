/**
 *	A loop equivalent to the for without using && and ||.
 */
#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void printline(char line[], int length);

main(){
	char line[MAXLINE];
	int length;

	while((length = getline(line, MAXLINE)) > 0){
		printline(line, length);
	}
}

/* Read a line of character and return its length */
int getline(char line[], int maxline){
	int i, c;
	for(i = 0; i < maxline; ++i){
		if((c = getchar()) == '\n')break;
		if(c == EOF)break;
		line[i] = c;
	}
	if(c == '\n')line[i++] = c;
	c = '\0';
	return i;
}

/* Print a line of character */
void printline(char line[], int length){
	int i;
	for(i = 0; i < length; ++i){
		putchar(line[i]);
	}
}