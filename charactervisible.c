/**
 *	Copy input to output, replacing each tab by \t, each backspace
 *  by \b, and each backslash by \\.
 */
#include <stdio.h>

 main(){
 	char c;

 	while((c = getchar()) != EOF){
 		if(c == '\b')printf("\\b");
 		else if(c == '\\')printf("\\\\");
 		else if(c == '\t')printf("\\t");
 		else putchar(c);
 	}
 }