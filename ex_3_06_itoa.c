/**
 *	The third argument is a minimum field width; the converted
 *	number must be padded with blanks on the left if necessary
 *	to make it wide enough
 */
#include <stdio.h>
#include <string.h>

void itoa(int n, char s[], int w);
void reverse(char s[]);

main(){
	char s[50];
	itoa(512, s, 6);
	printf("Integer: %d\nWide: %d\nString: %s", 512, 6, s);
}

void itoa(int n, char s[], int w){
	int i, sign;

	sign = n;
	i = 0;
	do{
		s[i++] = abs(n % 10) + '0';
	}while((n /= 10) > 0);
	if(sign < 0)
		s[i++] = '-';
	while(i < w){
		s[i++] = ' ';
	}
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[]){
	char i, j, c;
	for(int i = 0, j = strlen(s) - 1; i < j; i++, j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}