/**
 *	interchange two arguments of type t
 */
#include <stdio.h>

#define swap(t, x, y){t temp;\
temp = x;\
x = y;\
y = temp;}

main(){
	char x = 'a', y = 'b';
	printf("x = %c\ny = %c\n", x, y);
	swap(char, x, y);
	printf("x = %c\ny = %c\n", x, y);
}