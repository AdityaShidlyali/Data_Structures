// Author : Aditya Shidlyali

// Program to merge two sorted arrays

#include <stdio.h>

int main() {
	
	// read number of elements for first array
	int n1;
	printf("Enter number of elements for array A : ");
	scanf("%d", &n1);
	
	// read n1 number of elements for array A
	printf("Enter %d number of elements for array A one by one in ascending order : \n", n1);
	int i, a[n1];
	for (i = 0; i < n1; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	
	// read number of elements for second array
	int n2;
	printf("Enter number of array elements for array B : ");
	scanf("%d", &n2);
	
	// read n2 number of elements for array B
	printf("Enter %d number of elements for array B one by one in ascending order : \n", n2);
	for (i = 0; i < n2; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	
	// now add number of elements from array A and B
	int n = n1 + n2;
	int c[n];
	
	// now perform the operation
	
	
	return 0;
}
