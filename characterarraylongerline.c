/**
 *	Print all input lines that are longer than 80 
 * 	characters.
 */
#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void printline(char line[], int length);

main(){
	int len;
	char ca[MAXLINE];

	while((len = getline(ca, MAXLINE)) > 0){
		if(len + 1 > 80)
			printline(ca, len);
	}
}

/* Read a line into line and return length */
int getline(char line[], int maxline){
	int c, i;

	for(i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i){
		line[i] = c;
	}
	if(c == '\n'){
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

/* Print a line of characters */
void printline(char line[], int length){
	int i;

	for(i = 0; i < length; ++i){
		putchar(line[i]);
	}
}