/**
 * Print the value of EOF and show the result of c != EOF.
 */
#include <stdio.h>

main(){

	printf("EOF: %d\n", EOF);

	int c;

	while((c = getchar())!= EOF){
		printf("%c != EOF: %d", c, (c!=EOF));
		putchar('\n');
		putchar(c);
		putchar('\n');
	}
}