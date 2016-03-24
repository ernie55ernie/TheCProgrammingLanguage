/**
 *	reverse the string s in place
 */
#include <stdio.h>

int size;

void reverse(char s[], int n){
	if((size - n) >= n)
		return;
	char temp;
	temp = s[size - n - 1];
	s[size - n - 1] = s[n];
	s[n] = temp;
	reverse(s, n - 1);
}

main(){
	char s[] = "Hello world!";
	size = 12;
	printf("%s\n", s);
	reverse(s, size - 1);
	printf("%s\n", s);
}