/**
 *	Print a histogram of the length of words in input.
 */
#include <stdio.h>

 main(){
 	char c;
 	int hist[20];
 	int wordlength = 0, i, j;

 	for(i = 0; i < 20; i++){
 		hist[i] = 0;
 	}

 	while((c = getchar()) != EOF){
 		if(c == '\n' || c == '\t' || c == ' '){
 			++hist[wordlength];
 			wordlength = 0;
 		}else{
 			wordlength++;
 		}
 	}

	printf("Horizontal histogram\n");
	printf("length\tcount\n");
	printf("\t");
 	for(i = 1; i <= 20; i++)printf("%3d",i);
 	printf("\n");
 	for(i = 0; i < 20; i++){
 		printf("%d\t", i);
 		for(j = 0; j < hist[i]; j++){
 			printf("  -");
 		}
 		printf("\n");
 	}

 	printf("Vertical histogram\n");
 	for(i = 0; i <= 20; i++){
 		if(i == 19)printf("count");
 		else if(i == 20){
 			printf("length\t");
 			for(j = 0; j < 20; j++){
 				printf("%3d", j);
 			}
 		}
 		printf("\t%3d", i);
 		for(j = 0; j < 20 && i != 20; j++){
 			if((hist[j] + i) >= 20){
 				printf("  |");
 			}else{
 				printf("   ");
 			}
 		}
 		printf("\n");
 	}
 }