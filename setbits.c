/**
 *	Returm x with the n bits that begin at position p
 *	set to the rightmost n bits of y, leaving the 
 *	other bits unchanged.
 */
#include <stdio.h>

unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y);

main(){
	unsigned x = 64, y = 7, n = 3, p = 0;
	x = setbits(x, p, n, y);
	printf("setbits: %d\n", x);
}

/* setbits: Set the n bits begin at position p of x
 * to the rightmost n bits of y
 */
unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y){
	unsigned i, mask = 0;
	for(i = 0; i < n; ++i){
		mask <<= 1;
		mask |= 0x1;
	}
	y &= mask;
	y <<= p;
	x |= y;
	return x;
}