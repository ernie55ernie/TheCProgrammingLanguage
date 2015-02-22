/**
 *	Return the first location in the string s2 where any
 * 	character from the string s2 occurs, or -1 if s1 
 *	contains no characters from s2.
 */
#include <stdio.h>

int any(char s1[], char s2[]);
void printline(char line[]);

main(){
 	char s1[] = "how do you turn this on\0";
 	char s2[] = "turn";

 	int i = any(s1, s2);
 	printline(s1);
 	printf("%d", i);
}

/* any: return the first location in the string s2 where
 * character from the string s2 occurs, or -1 if s1 
 * contains no characters from s2 */
int any(char s1[], char s2[]){
	int i, j;
	for(i = 0; s2[i] != '\0'; ++i){
		for(j = 0; s1[j] != '\0'; ++j){
			if(s2[i] == s1[j]){
				return j;
			}
		}
	}
}

/* Print all characters of a line */
void printline(char line[]){
	int i;
	for(i = 0; line[i] != '\0'; ++i){
		putchar(line[i]);
	}
}