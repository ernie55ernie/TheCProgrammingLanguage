/**
 *	Expand shorthand notations like a-z in a string s1 into the equivalent 
 *  complete list abc...xyz in s2. Allow for letters of either case and 
 *  digits.
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void expand(char s1[], char s2[]);

main(){

	char s1[] = "a-b-c\na-z0-9\n-a-z";
	char s2[1000];

	expand(s1, s2);

	printf("s1: %s\ns2: %s\n", s1, s2);
}

void expand(char s1[], char s2[]){

	int n = strlen(s1);

	for(int i = 0, j = 0; i < n; i++){
		if((isdigit(s1[i]) && i + 2 < n && s1[i + 1] == '-' && isdigit(s1[i + 2])) ||
			(isalpha(s1[i]) && i + 2 < n && s1[i + 1] == '-' && isalpha(s1[i + 2]))){
			for(int k = 0; k <= s1[i + 2] - s1[i]; k++){
				s2[j++] = s1[i] + k;
			}
			i += 2;
		}else if((s1[i] == '-' && i > 0 && i + 1 < n && isdigit(s1[i - 1]) && isdigit(s1[i + 1])) ||
			(s1[i] == '-' && i > 0 && i + 1 < n && isalpha(s1[i - 1]) && isalpha(s1[i + 1]))){
			for(int k = 1; k <= s1[i + 1] - s1[i - 1]; k++){
				s2[j++] = s1[i - 1] + k;
			}
			i += 1;
		}else{
			s2[j++] = s1[i];
		}
	}

}