// Author : Aditya Shidlyali

// Program to interchange the smalles and the largest element from the array

#include <stdio.h>

// user functions used in this program are :
int findSmallestElementPos(int *, int);
int findLargestElementPos(int *, int);
void interchangeSmallestAndLargest(int *, int);

int main() {
	
	// read the number of elements
	int n;
	printf("Enter number of elements : ");
	scanf("%d", &n);
	
	// read n number of elements one by one
	int i, a[n];
	for (i = 0; i < n; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	
	// now call the interchangeSmallestAndLargest function to swap the largest and the smallest elements
	// which inturn it calls the functions findLargestElementPos and findSmallestElementPos to get the positions of the smallest and the largest element in the array
	interchangeSmallestAndLargest(a, n);
	
	// print the final array after swapping the smallest and largest elements from the array	
	printf("The final array after swapping is : \n");
	for (i = 0; i < n; i++) {
		printf("a[%d] = %d\n", i, a[i]);
	}
	
	return 0;
}

// function which interchanges the Smallest and Largest elements
void interchangeSmallestAndLargest(int *a, int n) {
	
	// define two variables to store the position of the smalles and largest element.
	int smallestPosition, largestPosition;
	
	// call the findSmallestElementPos to find the smallest element from the array
	smallestPosition = findSmallestElementPos(a, n);
	
	// call the findLargestElementPos to find the smallest element from the array
	largestPosition = findLargestElementPos(a, n);
	
	// now swap the elements
	int temp = a[smallestPosition];
	a[smallestPosition] = a[largestPosition];
	a[largestPosition] = temp;
}

// function to find the position of the Smallest element from the array
int findSmallestElementPos(int *a, int n) {
	
	// assume the smallest element is at the position 0 of the array
	int smallPos = 0, i;
	
	// now find the smallest element from the array by compairing with the smalle
	for(i = 0; i < n; i++) {
		if (a[i] < a[smallPos]) {
			smallPos = i;
		}
	}
	
	// now return the smallPos 
	return smallPos;
}

// function to find the position of the Largest element from the array
int findLargestElementPos(int *a, int n) {
	
	// assume the smallest element is at the position 0 of the array
	int largePos = 0, i;
	
	// now find the smallest element from the array by compairing with the smalle
	for(i = 0; i < n; i++) {
		if (a[i] > a[largePos]) {
			largePos = i;
		}
	}
	
	// now return the smallPos 
	return largePos;
}
