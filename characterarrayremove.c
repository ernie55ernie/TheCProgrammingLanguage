/**
 *	Remove trailing blanks and tabs from each line of input, 
 *	and delete entire blank lines.
 */
#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void printline(char line[], int length);

main(){
	char cl[MAXLINE];
	int n;

	while((n = getline(cl, MAXLINE)) > -1){
		printline(cl, n);
	}
}

/* Read a line into line, remove its blanks and tabs and return length */
int getline(char line[], int maxline){
	int c, i = 0;

	while(i < maxline - 1 && (c = getchar()) != EOF && c != '\n'){
		if(c == ' ' || c == '\t')continue;
		line[i++] = c;
	}
	if(c == '\n'){
		if(i == 0)return i;
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	if(c == EOF)i = -1;
	return i;
}

/* Print a line of characters */
void printline(char line[], int length){
	int i;

	for(i = 0; i < length; i++){
		putchar(line[i]);
	}
}