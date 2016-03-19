/**
 *	Reverse input a line at a time.
 */
#include <stdio.h>
#define MAXLINE 1000

 int getline(char line[], int maxline);
 void printline(char line[], int length);
 void reverse(char line[], int length);

 main(){
 	int n;
 	char cl[MAXLINE];

 	while((n = getline(cl, MAXLINE)) > 0){
 		reverse(cl, n);
 		printline(cl, n);
 	}
 }

 /* Read a line into line and return length */
 int getline(char line[], int maxline){
 	int c, i;

 	for(i = 0; i < maxline && (c = getchar()) != EOF && c != '\n'; ++i){
 		line[i] = c;
 	}
 	if(c == '\n')line[i++] = c;
 	line[i] = '\0';
 	return i;
 }

 /* Print a line of characters */
 void printline(char line[], int length){
 	int i;
 	for(i = 0; i < length; i++){
 		putchar(line[i]);
 	}
 }

/* Reverse a line */
void reverse(char line[], int length){
	char rev[MAXLINE];
	int i;

	for(i = 0; i < length; i++){
		rev[i] = line[length - i - 2];
	}
	for(i = 0; i < length - 1; i++){
		line[i] = rev[i];
	}
}