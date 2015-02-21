/**
 *	Determines the ranges of char, short, int, and long
 *	variables, both signed and unsigned. Determine the range
 *	of the various float-point types.
 */
#include <stdio.h>

main(){
	int i, j;
	for(i = 0, j = i;; i++){
		if(i < j)
			break;
		j = i;
	}
	printf("int\tupper limit: %d\n", j);
	for(i = 0, j = i;; i--){
		if(i > j)
			break;
		j = i;
	}
	printf("\tlower limit: %d\n", j);

	char c, d;
	for(c = 0, d = c;; c++){
		if(c < d)
			break;
		d = c;
	}
	printf("chat\tupper limit: %c\n", d);
	for(c = 0, d = c;; c--){
		if(c > d)
			break;
		d = c;
	}
	printf("\tlower limit: %c\n", d);

	short s, t;

	long l, m;
}