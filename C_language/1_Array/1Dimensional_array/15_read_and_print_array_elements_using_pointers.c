// Author : Aditya Shidlyali

// Program to read and print the array elements using pointers

#include <stdio.h>

int main() {
	
	// read number of array elements
	int n;
	printf("Enter number of elements : ");
	scanf("%d", &n);
	
	// read n number of array elements one by one
	printf("Enter %d number of elements one by one : \n", n);
	int i, a[n];
	for (i = 0; i < n; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	
	// define the pointer of the type array
	int *ptr = a; // which points to the first address of the array
	i = 0;
	printf("Entered array elements are : \n");
	while (i < n) {
		printf("a[%d] = %d\n", i, *ptr);
		ptr++;
		i++;
	}
	
	return 0;
}
