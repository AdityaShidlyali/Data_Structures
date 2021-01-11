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
	int b[n2];
	for (i = 0; i < n2; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &b[i]);
	}
	
	// now add number of elements from array A and B
	int n = n1 + n2;
	int c[n];
	
	int index = 0, index_first = 0, index_second = 0;
	
	// now perform the merging operation
	while (index_first < n1 && index_second < n2) {
		
		// check which element is greater and start inesrting the smallest element to the combining array 'c'
		if (a[index_first] < b[index_second]) {
			c[index] = a[index_first];
			index_first++;
		} else {
			c[index] = b[index_second];
			index_second++;
		}
		
		// increase the index of combining array
		index++;
	}
	
	// if the index of the first array has reached the mximum length of the array
	// then insert the remaining elements from the second array to the combining array 'c'
	if (index_first == n1) {
		while (index_second < n2) {
			c[index] = b[index_second];
			index_second++;
			index++;
		}
	}
	
	// if the index of the second array has reached the maximum lenght of the array
	// then insert the remaining elements from the first array to the combining array'c'
	if (index_second == n2) {
		while (index_first < n1) {
			c[index] = a[index_first];
			index_first++;
			index++;
		}
	}
	
	// now print the final array c
	printf("The final array after merging is : \n");
	for (i = 0; i < n; i++) {
		printf("c[%d] = %d\n", i, c[i]);
	}
	
	return 0;
}
