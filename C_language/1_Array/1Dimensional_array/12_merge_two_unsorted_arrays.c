// Author : Aditya Shidlyali

// Program to merge two unsorted arrays

#include <stdio.h>

int main() {
	
	// read the number of elements for array A
	int n1;
	printf("Enter number of elements for array A: ");
	scanf("%d", &n1);
	
	// read the n1 number of elements for the first array
	printf("Enter %d number of elements for the array A one by one : \n", n1);
	int i, a[n1];
	for (i = 0; i < n1; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	
	// read the number of elements for array B
	int n2;
	printf("Enter number of elements for array B: ");
	scanf("%d", &n2);
	
	// read n2 number of array elements for second array
	printf("Enter %d number of elements for the array B one by one : \n", n2);
	int b[n2];
	for (int i = 0; i < n2; i++) {
		printf("b[%d] = ", i);
		scanf("%d", &b[i]);
	}
	
	int n = n1 + n2; // now add number of array elements
	int c[n]; // create new array of size n to merge two arrays
	
	// define the variable index to continue the merging process after the first array
	int index = 0;
	
	// now copy the elements from the first array 
	for (i = 0; i < n1; i++, index++) {
		c[index] = a[i];
	}
	
	// now copy the elements fromt the second array
	for (i = 0; i < n2; i++, index++) {
		c[index] = b[i];
	}
	
	// now print the final array c
	printf("The final array after combining two arrays is : \n");
	for (i = 0; i < n; i++) {
		printf("c[%d] = %d\n", i, c[i]);
	}
		
	return 0;
}
