/**
 *	Deletes each character in s1 that matches any character 
 *	in the string s2.
 */
#include <stdio.h>

void squeezeone(char s[], int c);
void squeeze(char s[], char ca[]);
void printline(char s[]);

main(){
	char s[] = "how do you turn this on\0";
	char c[] = "how\0";

	squeeze(s, c);
	printline(s);
}

/* squeezeone: delete all c from s */
void squeezeone(char s[], int c){
	int i, j;
	for(i = j = 0; s[i] != '\0'; ++i)
		if(s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
}

/* squeeze: delete all characters in c from s */
void squeeze(char s[], char ca[]){
	int i;
	for(i = 0; ca[i] != '\0'; ++i){
		squeezeone(s, ca[i]);
	}
}

/* printline: print all characters in a character array */
void printline(char s[]){
	int i;
	for(i = 0; s[i] != '\0'; ++i){
		putchar(s[i]);
	}
}