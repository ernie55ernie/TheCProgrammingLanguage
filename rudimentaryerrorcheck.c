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

	/* Get characters from file */
	f = freopen("syntaxcheck.c", "r", stdin);
	while((c = getchar()) != EOF){
		putchar(c);
	}

	fclose(f);
}