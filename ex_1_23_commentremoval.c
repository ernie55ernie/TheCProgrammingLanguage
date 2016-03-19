/**
 *	Remove all comments from a C program.
 *	Handle quoted strings and character 
 *	constants properly. C comments
 *	does not nest.
 */
#include <stdio.h>
#define MAXLINE 1000

typedef enum{
	false = 0,
	true = 1
}bool;

int getline(char line[], int maxline);
void printline(char line[], int length);

main(){
	FILE *f;
	char cl[MAXLINE];
	int n;

	/* Get characters from file */
	f = freopen("syntaxcheck.c", "r", stdin);
	while((n = getline(cl ,MAXLINE)) > 0){
		printline(cl, n);
	}

	fclose(f);
}

/**
 *	Read a line from input and return length.
 */
int getline(char line[], int maxline){
	int i, c;
	bool blockcomment = false, inlinecomment = false,
		 singlequote = false, doublequote = false;
	for(i = 0; i < maxline && (c = getchar()) != EOF;){

		if(inlinecomment){
			if(c == '\n'){
				inlinecomment = false;
			}
		}

		else if(blockcomment){
			if(c == '*'){
				c = getchar();
				if(c == '/'){
					blockcomment = false;
				}
			}
		}

		else if(c == '/' && !singlequote && !doublequote){
			c = getchar();
			if(c == '/'){
				inlinecomment = true;
			}

			if(c == '*'){
				blockcomment = true;
			}

		}

		else{

			if(c == '"'){
				if(!doublequote) doublequote = true;
				else doublequote = false;
			}

			if(c == '\''){
				if(!singlequote) singlequote = true;
				else singlequote = false;
			}

			line[i++] = c;
		}
	}
	line[i] = '\0';
	return i;
}

/**
 *	Print a line of characters.
 */
void printline(char line[], int length){
	int i;
	for(i = 0; i < length; ++i){
		putchar(line[i]);
	}
}