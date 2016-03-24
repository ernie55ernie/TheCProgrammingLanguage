/**
 *	handle scientific notation of the form
 */
#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof(char s[]){
	double val, power, exp10 = 0;
	int i, sign;

	for(i = 0; isspace(s[i]); i++) /* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '+' || s[i] == '-')
		i++;
	for(val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if(s[i] == '.')
		i++;
	for(power = 1.0; isdigit(s[i]); i++){
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	if(s[i] == 'E' || s[i] == 'e'){
		exp10 = atof(&s[++i]);
	}
	return sign * val / power * pow(10, exp10);
}

main(){
	char sci[] = "123.45e-6";
	printf("%s: %.10lf", sci, atof(sci));
}