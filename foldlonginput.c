/**
 *	Fold long input lines into two or more shorter 
 *	lines after the last non-blank character that 
 *	occurs before the n-th column of input.Do 
 *	something intelligent with very long lines,
 *	and if there are no blanks or tabs before
 *	the specified column.
 */
#include <stdio.h>
#define FOLDCOLUMN 10
#define MAXLINE 1000

int getline(char line[], int maxline);
int fold(char line[], int length);
void addchar(char c, char line[], int pos, int length);
void printline(char line[], int length);

main(){
	int i;
	char line[MAXLINE];

	while((i = getline(line, MAXLINE)) > 0){
		printline(line, i);
	}
}

/* Read a line of characters from input and return length */
int getline(char line[], int maxline){
	int i, c;
	
	for(i = 0; i < maxline && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if(c == '\n') line[i++] = c;
	line[i] = '\0';
	return fold(line, i);
}

/* Fold along input lines */
int fold(char line[], int length){
	int cl = 0, lb = 0, i, llb = lb;
	for(i = 0; i < length; ++i){
		if(cl >= FOLDCOLUMN){
			cl = 0;
			if(lb != llb)addchar('\n', line, lb, length++);
			else{
				addchar('-', line, i, length++);
				addchar('\n', line, i + 1, length++);
				addchar('-', line, i + 2, length++);
			}
		}else{
			cl++;
			if(line[i] == ' ')lb = i;
		}
	}
	return length;
}

/* Add a newline symbol at pos in the character array with a specified
	length */
void addchar(char c, char line[], int pos, int length){
	int i;
	for(i = length - 1; i >= pos; --i){
		line[i + 1] = line[i];
	}
	line[pos] = c;
}

/* Print a line of characters with specified length */
void printline(char line[], int length){
	int i;
	for(i = 0; i < length; i++)
		putchar(line[i]);
}