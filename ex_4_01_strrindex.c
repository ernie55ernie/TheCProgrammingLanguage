/**
 *	Return the poisition of the rightmost occurance of t in s, or -1 if there is none.
 */
#include <stdio.h>

int strrindex(char s[], char t[]){

	int i, j, k, last = -1;

	for(i = 0; s[i] != '\0'; i++){
		for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++);

		if(k > 0 && t[k] == '\0')
			last = i;
	}
	return last;
};

main(){
	char pattern[] = "ould";
	char line[] = "Maybe I would go to the library. Since I could get a book.";

	printf("strrindex: %d\n", strrindex(line, pattern));
} 