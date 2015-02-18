/**
 *	Print a histogram of the frequencies of differenct character
 *	in input.
 */
#include <stdio.h>

 main(){
 	char c;
 	int freq[52];
 	int i, j;

 	for(i = 0; i < 52; i++){
 		freq[i] = 0;
 	}

 	while((c = getchar()) != EOF){
 		if(c >= 'A' && c <= 'Z'){
 			freq[c - 'A']++;
 		}else if(c >= 'a' && c <= 'z'){
 			freq[c - 'a' + 26]++;
 		}
 	}

 	printf("Horizontal histogram\n");
 	printf("character\tcount\n\t");
 	for(i = 1; i <= 20; i++){
 		printf("  %d", i);
 	}
 	printf("\n");
 	for(i = 0; i < 52; i++){
 		if(i < 26)printf("%c\t", i + 'A');
 		else printf("%c\t", i - 26 + 'a');
 		for(j = 0; j < freq[i]; j++){
 			printf("  -");
 		}
 		printf("\n");
 	}

 }