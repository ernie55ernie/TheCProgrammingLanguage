/**
 *	Convert the integer n into a base b character representation
 *	in the string s. In particular, itob(n, s, 16) formats n as
 *	a hexadecimal integer in s.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

main(){
	char s[50];
	itob(522, s, 16);
	printf("Integer: %d\nBase: %d\nString: %s", 522, 16, s);
}

void itob(int n, char s[], int b){
	int i, sign;

	sign = n;
	i = 0;
	do{		/* generate digits in reverse order */
		int num = abs(n % b);
		if(num < 10)
			s[i++] = abs(n % b) + '0';	/* get next digit */
		else
			s[i++] = num - 10 + 'A';
	}while((n /= b) > 0);		/* delete it */
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