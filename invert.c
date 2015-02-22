/**
 *	Return x with the n bits that begin at position p
 *	inverted (i.e., 1 changed into 0 and vice versa),
 *	leaving the others unchaged.
 */
#include <stdio.h>

unsigned invert(unsigned x, unsigned p, unsigned n);

main(){
	unsigned x = 64, p = 0, n = 3;
	x = invert(x, p, n);
	printf("invert: %d\n", x);
}

/* invert: invert the n bits that begin at position p
 *  of x
 */
unsigned invert(unsigned x, unsigned p, unsigned n){
	unsigned mask = 0;
	for(;n > 0;--n){
		mask <<= 1;
		mask |= 1;
	}
	x ^= mask;
	return x;
}