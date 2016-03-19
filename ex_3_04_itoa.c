/**
 *	In a two's complement number representation, print the largest negative
 *  number correctly, regardless of the machine on which it runs.
 */
#include <stdio.h>
#include <string.h>
#include <limits.h>

/* itoa:	convert n to characters in s */
void itoa(int n, char s[]);
void reverse(char s[]);

main(){
	char s[50];
	itoa(INT_MIN, s);
	printf("Integer: %d\nString: %s", INT_MIN, s);
}

void itoa(int n, char s[]){
	int i, sign;

	sign = n;
	i = 0;
	do{		/* generate digits in reverse order */
		s[i++] = abs(n % 10) + '0';	/* get next digit */
	}while((n /= 10) > 0);		/* delete it */
	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[]){
	int i, j, c;
	for(i = 0, j = strlen(s) - 1; i < j; i++, j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}