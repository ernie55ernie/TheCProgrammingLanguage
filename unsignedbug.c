#include <stdio.h>

int array[] = {23, 34, 12, 17, 204, 99, 16};
#define TOTAL_ELEMENTS (sizeof(array) / sizeof(array[0]))

main(){
	int d = -1, x = 0;

	if(d < TOTAL_ELEMENTS - 2)
		x = array[d + 1];

	printf("x: %d, array[d + 1]: %d", x, array[d + 1]);
}