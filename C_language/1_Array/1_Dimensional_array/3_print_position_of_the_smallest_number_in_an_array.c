// Author : Aditya Shidlyali

// print the position of smallest element in an array

#include <stdio.h>

int main() {
	
	// read the number of elements to be stored
	int n;
	printf("Enter number of elements : ");
	scanf("%d", &n);
	
	// read the n number of elements one by one
	int a[n], i;
	printf("Enter %d number of elements one by one : \n", n);
	for (i = 0; i < n; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	
	// assume that the first number is the smallest number and also the position to be zero
	// and compare it with all the array elements and if any small element is found update the small and postion variables.
	int small = a[0], pos = 0;
	for (i = 0; i < n; i++) {
		if (small > a[i]) {
			small = a[i];
			pos = i;
		}
	}
	
	// print the smallest element and also its position
	printf("The smallest element = %d", small);
	printf("\nThe position of the smallest element = %d", pos);
	
	return 0;
}
