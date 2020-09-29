// Author : Aditya Shidlyali

// find the mean of array elements

#include <stdio.h>

int main() {
	
	// read the number of elements to be stored
	int n;
	printf("Enter number of elements : ");
	scanf("%d", &n);
	
	// read n number of elements one by one
	int i, a[n];
	printf("Enter %d number of elements one by one : \n", n);
	for (int i = 0; i < n; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	
	// take the sum of the elements
	int sum = 0;
	for (i = 0; i < n; i++) {
		sum += a[i];
	}
	
	// calculate the mean
	float mean = (float)sum / n;
	
	// print the mean and sum
	printf("The sum of the elements = %d", sum);
	printf("\nThe mean of the elements = %.2f", mean);
	
	return 0;
}
