/**
 *	In a two's complement number system, x &= (x - 1)
 *	 deletes the rightmost 1-bit in x. Write a faster
 *	version of bitcount.
 */
#include <stdio.h>

int bitcount(unsigned x);

main(){

}

/* bitcount: count 1 bits in x */
int bitcount(unsigned x){
	int b;

	for(b = 0; x != 0; x >> 1)
		if(x & 01)
			b++;

	return b;
}