/**
 *	Rewite lower, which converts upper case letters
 *	to lower case, with a conditional expression instead
 *	of if-else.
 */
#include <stdio.h>

void lower(char line[]);
void printline(char line[]);

main(){
	char line[] = "How Do yOU tUrN ThiS ON\0";
	lower(line);
	printline(line);
}

/* lower: convert upper case letters to 
 * lower case letter
 */
void lower(char line[]){
	int i;
	for(i = 0; line[i] != '\0'; ++i){
		line[i] = line[i] <= 'Z' && line[i] >= 'A' ? 
		(line[i] - 'A' + 'a') : line[i];
	}
}

/* printline: print a line of characters */
void printline(char line[]){
	int i;
	for(i = 0; line[i] != '\0'; ++i)
		putchar(line[i]);
}