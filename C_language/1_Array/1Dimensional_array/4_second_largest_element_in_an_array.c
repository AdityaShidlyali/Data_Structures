// Author : Aditya Shidlyali

// second largest element in an array

#include <stdio.h>

int main() {
	
	// read how many elements to be stored
	int n;
	printf("Enter number of elements : ");
	scanf("%d", &n);
	
	// read n number of elements one by one
	int i, a[n];
	printf("Enter %d number of elements one by one : \n", n);
	for (i = 0; i < n; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	
	// we will take the largest element of the array
	int largest = a[0];
	for (i = 0; i < n; i++)	{
		if (largest < a[i]) {
			largest = a[i];
		}
	}
	
	// we will now consider the first element as the secondLargest and if we encounter the largest element we will skip it
	int secondLargest = a[0];
	for (i = 0; i < n; i++) {
		if (secondLargest < a[i] && a[i] != largest) {
			secondLargest = a[i];
		}
	}
	
	// print the largest as well as second largest element
	printf("Largest element in the array is = %d", largest);
	printf("\nThe second largest element in array is = %d", secondLargest);
	
	return 0;
}
