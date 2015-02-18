/**
 *	Copy input to output, replacing  each string of one or blanks by
 *	a single blank.
 */
#include <stdio.h>

main(){

	int blank = 0;
	char c;

	while((c = getchar())!= EOF){
		if(c == ' ' && blank)continue;
		else putchar(c);

		if(c == ' ')blank++;
		else blank = 0;
	}
}