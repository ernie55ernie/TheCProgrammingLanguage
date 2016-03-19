/**
 * Convert characters like newline and tab into visible escape sequence like 
 * \n and \t as it copies the string t to s
 */
#include <stdio.h>
#include <string.h>

void escape(char* s, char* t);

main(){
	char s[] = "\nHow do you turn this on?\tB\nA\t\0";
	int n = strlen(s);
	char t[2 * n];

	escape(s, t);

	printf("s: %s\nt: %s\n", s, t);
}

void escape(char* s, char* t){
	int n = strlen(s);
	for(int i = 0, j = 0; i < n; i++){
		switch(s[i]){
		case '\n':
			t[j++] = '\\';
			t[j++] = 'n';
			break;
		case '\t':
			t[j++] = '\\';
			t[j++] = 't';
			break;
		case '\0':
			t[j++] = '\\';
			t[j++] = '0';
			break;
		case '\b':
			t[j++] = '\\';
			t[j++] = 'b';
			break;
		case '\\':
			t[j++] = '\\';
			t[j++] = '\\';
			break;
		default:
			t[j++] = s[i];
			break;
		}
	}
}