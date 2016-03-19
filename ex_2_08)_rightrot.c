/**
 *	Return the value of integer x rotated to the right 
 *	by n bit positions.
 */
#include <stdio.h>

int rightrot(int x, unsigned n);

main(){
	unsigned x = 64, n = 1;
	x = rightrot(x, n);
	printf("rightrot: %d", x);
}

/* rightrot: rotate to the right by n bit positions of x */
int rightrot(int x, unsigned n){
	unsigned mask = 0, bit = 0, i;
	for(i = x; i > 0; i >>= 1, bit++);
	for(i = n; i > 0; --i){
		mask <<= 1;
		mask |= 1;
	}
	x = (x >> n) | (x & mask) << (bit - n);
	return x;
}