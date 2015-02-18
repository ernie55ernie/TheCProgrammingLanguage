/**
 *	Downward Fahrenheit-Celsius table from 300 to 0
 */
#include <stdio.h>

main(){
	int fahrenheit;

	printf("Fahrenheit\tCelsius\n");
	for(fahrenheit = 300; fahrenheit >= 0; fahrenheit -= 20){
		printf("\t%3d\t%6.1f\n", fahrenheit, (5.0 / 9.0) * (fahrenheit - 32));
	}
}