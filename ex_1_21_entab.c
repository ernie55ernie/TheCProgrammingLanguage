/**
 *	Replace strings of blanks by the minimum number
 *	tabs and blanks to achieve the same spacing.
 *	Use the same tab stops as for detab.
 */
#include <stdio.h>
#define TABSTOP 8

main(){
	int i, c, b = 0;

	while((c = getchar()) != EOF){
		if(c == ' '){
			b = 1;
			while((c = getchar()) == ' '){
				b++;
			}
			for(i = b; i > 0; i -= TABSTOP){
				putchar('\t');
			}
			b = 0;
			putchar(c);
		}else{
			putchar(c);
		}
	}
}