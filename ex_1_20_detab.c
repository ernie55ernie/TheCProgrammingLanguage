/**
 *	Replace tabs in the input with the proper
 *	number of blanks to space to the next tab
 *	stop. Assume a fixed step of tab stops,
 *	say every n columns.
 */
#include <stdio.h>
#define TABSTOP 8

main(){
	int c, i, s = 0;

	while((c = getchar()) != EOF){
		if(s%TABSTOP == 0)s = 0;
		if(c == '\t'){
			for(i = 0; i < TABSTOP - s; ++i)putchar(' ');
			s = 0;
		}else{
			putchar(c);
			++s;
		} 
	}
}