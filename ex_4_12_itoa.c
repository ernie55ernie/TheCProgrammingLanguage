/**
 *	convert an integer into a string by calling a recursive routine
 */
#include <stdio.h>
#include <string.h>

int indexi;
int sign;

void reverse(char s[]){
	int i, j, c;
	for(i = 0, j = strlen(s) - 1; i < j; i++, j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void itoa(int n, char s[]){
	if(abs(n) == 0){
		if(sign < 0)
			s[indexi++] = '-';
		s[indexi] = '\0';
		reverse(s);
		return;
	}else{
		sign = n;
		s[indexi++] = abs(n % 10) + '0';	/* get next digit */
		itoa(n / 10, s);
	}
}

main(){
	int i = -502;
	indexi = 0;
	char s[50];
	itoa(i, s);
	printf("%d: %s", i, s);
}