/**
 *	Converts a string of hexadecimal digits (including 
 *	 0x and 0X) into its equivalent integer value.
 *	The allowable digits are 0 through 9, a through
 *	f, and A through F.
 */
#include <stdio.h>
#include <math.h>
#define MAXLINE 1000

int gethexa(char hexa[], int maxline);
void printhexa(char hexa[], int length);
int htoi(char hexa[], int length);

main(){
	char line[MAXLINE];
	int i = 0, d = 0;

	while((i = gethexa(line, MAXLINE)) > 0 || i == -1){
		if(i == -1){
			printf("Invalid hexadecimal number\n");
			continue;
		}
		d = htoi(line, i);
		printhexa(line, i);
		printf(" is equivalent to %d\n", d);
	}
}

/* Read hexaecimal digits and return its length */
int gethexa(char hexa[], int maxline){
	int i, c;
	for(i = 0; i < MAXLINE && (c = getchar()) != '\n' && c != EOF; ++i){
		if((c > '9' && c < '0') &&
		 (c > 'z' && c < 'a') && 
		 (c > 'Z' && c < 'A'))
			return -1;
		hexa[i] = c;
	}
	if(c == '\n') hexa[i++] = '\n';
	hexa[i] = '\0';
	if(hexa[0] != '0' || (hexa[1] != 'x' && hexa[1] != 'X'))return -1;
	return i;
}

/* Print a hexadecimal number in character array */
void printhexa(char hexa[], int length){
	int i;
	for(i = 0; i < length - 1; ++i)
		putchar(hexa[i]);
}

/* Convert hexadecimal digits into its equivalent 
 * integer value.
 */
int htoi(char hexa[], int length){
	int i, d = 0, c;
	for(i = 2; i < length - 1; ++i){
		c = hexa[i];
		if(c >= '0' && c <= '9') c = c - '0'; 
		else if(c >= 'a' && c <= 'z') c = c - 'a' + 10;
		else c = c - 'A' + 10;
		d += pow(16, (length - 2 - i)) * c;
	}
	return d;
}