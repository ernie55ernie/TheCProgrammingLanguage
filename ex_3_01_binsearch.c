/**
  *	Write a version will only one test inside the loop and measure
  *	the difference in run-time

v[]: 1, 3, 8, 10, 14, 50, 69, 100, 123, 178, 206, 598, 741
x: 3
binsearch: 1
real    0m0.414s
user    0m0.000s
sys     0m0.000s

v[]: 1, 3, 8, 10, 14, 50, 69, 100, 123, 178, 206, 598, 741
x: 125
binsearch: -1
real    0m0.014s
user    0m0.000s
sys     0m0.015s

  */
#include <stdio.h>

/* binsearch:	find x in v[0] <= v[1] <= ... <= v[n - 1] */
int binsearch(int x, int v[], int n);

main(){
	int v[] = {1, 3, 8, 10, 14, 50, 69, 100, 123, 178, 206, 598, 741};
	int x = 125;
	int n = sizeof(v) / sizeof(v[0]);

	printf("v[]: %d", v[0]);
	for(int i = 1; i < n; i++){
		printf(", %d", v[i]);
	}
	printf("\nx: %d\nbinsearch: %d", x, binsearch(x, v, n));
}

int binsearch(int x, int v[], int n){

	int low, high, mid;

	low = 0;
	high = n - 1;
	while(low <= high){
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}

	if(v[mid] == x)
		return mid;

	return -1; /* no match */

}