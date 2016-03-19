/**
 *	Fahrenheit-Celsius table and Celsius-Fahrenheit table
 */
#include <stdio.h>

main(){
	float celsius, fahrenheit;

	int lower = 0, upper = 300, step = 20;

	/** The following prints the Fahrenheit-Celsius table */

	fahrenheit = lower;

	printf("Fahrenheit\tCelsius\n");

	while(fahrenheit <= upper){
		celsius = 5 * (fahrenheit - 32) / 9;

		printf("\t%3.0f\t%6.1f\n", fahrenheit, celsius);

		fahrenheit += step;
	}

	printf("\n\n");

	/** The following prints the Celsius-Fahrenheit table */

	lower = -20;
	upper = 150;
	step = 15;

	celsius = lower;

	printf("Celsius\tFahrenheit\n");

	while(celsius <= upper){
		fahrenheit = celsius * 9 / 5 + 32;

		printf("\t%3.0f\t%6.1f\n", celsius, fahrenheit);

		celsius += step;
	}
}