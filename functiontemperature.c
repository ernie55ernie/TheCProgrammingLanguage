/**
 *	Temperature transfer function.
 */
#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float FtoC(float f);

 main(){

 	float fahrenheit;

 	printf();
 	for(fahrenheit = LOWER; fahrenheit < UPPER; fahrenheit += STEP){
 		printf("%3.0f%6.1f", fahrenheit, FtoC(fahrenheit));
 	}

 }

 float FtoC(float f){
 	return 9.0 / 5.0 * (f - 32);
 }

