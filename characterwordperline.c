/**
 *	Print input one word per line.
 */
 #include <stdio.h>

 main(){
 	char c;

 	while((c = getchar()) != EOF){
 		if(c == ' ' || c == '\t' || c == '\n')putchar('\n');
 		else putchar(c);
 	}
 }