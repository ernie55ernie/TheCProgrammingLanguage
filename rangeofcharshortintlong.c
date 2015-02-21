/**
 *	Determines the ranges of char, short, int, and long
 *	variables, both signed and unsigned. Determine the range
 *	of the various float-point types.
 */
#include <stdio.h>

main(){
	int i, j;
	for(i = 0, j = i;; i++){
		if(i < j)
			break;
		j = i;
	}
	printf("int\tupper limit: %d\n", j);
	for(i = 0, j = i;; i--){
		if(i > j)
			break;
		j = i;
	}
	printf("\tlower limit: %d\n", j);

	char c, d;
	for(c = 0, d = c;; c++){
		if(c < d)
			break;
		d = c;
	}
	printf("chat\tupper limit: %c\n", d);
	for(c = 0, d = c;; c--){
		if(c > d)
			break;
		d = c;
	}
	printf("\tlower limit: %c\n", d);

	short s, t;
	for(s = 0, t = s;; s++){
		if(s < t)
			break;
		t = s;
	}
	printf("short\tupper limit: %d\n", t);
	for(s = 0, t = s;; s--){
		if(s > t)
			break;
		t = s;
	}
	printf("\tlower limit: %d\n", t);

	long l, m;
	for(l = 0, m = l;; l++){
		if(l < m)
			break;
		m = l;
	}
	printf("long\tupper limit: %d\n", m);
	for(l = 0, m = l;; l--){
		if(l > m)
			break;
		m = l;
	}
	printf("\tloewr limit: %d\n", m);

	signed g, h;
	for(g = 0, h = g;; ++g){
		if(g < h)
			break;
		h = g;
	}
	printf("signed\tupper limit: %d\n", g);
	for(g = 0, h = g;; --g){
		if(g > h)
			break;
		h = g;
	}
	printf("\tlower limit: %d\n", g);

	unsigned u, v;
	for(u = 0, v = u;; ++u){
		if(u < v)
			break;
		u = v;
	}
	printf("unsignedupper limit: %d\n", v);
	for(u = 0, v = u;; --u){
		if(u > v)
			break;
		u = v;
	}
	printf("\tlower limit: %d\n", v);
}