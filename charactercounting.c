/**
 * 	Count blanks, tabs, and newlines.
 */
#include <stdio.h>

main(){

	int blank = 0, tab = 0, newline = 0;
	char c;

	while((c = getchar()) != EOF){
		if(c == ' ')
			blank++;
		else if(c == '\t')
			tab++;
		else if(c == '\n')
			newline++;

		printf("blank: %d, tab: %d, newline: %d\n", blank, tab, newline);
	}

}