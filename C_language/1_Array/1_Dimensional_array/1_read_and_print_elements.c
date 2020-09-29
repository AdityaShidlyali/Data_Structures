// Author : Aditya Shidlyali

// program to read and print the array elements

#include <stdio.h>

int main() {
	
	// read the number of elements to be stored inside array
	int n;
	printf("Enter number of elements : ");
	scanf("%d", &n);
	
	// read the n number of array elements one by one		
	int i, a[n]; // allocate the memory accoerding to the number of elements
	printf("Enter %d number of elements one by one : \n", n);
	for (i = 0; i < n; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	
	// print the elements one by one
	printf("\nEntered elemets are : \n");
	for (i = 0; i < n; i++) {
		printf("a[%d] = %d\n", i, a[i]);
	}
	
	return 0;
}
