// Author : Aditya Shidlyali

// insert an array element in an already sorted array

#include <stdio.h>

int main() {
	
	// read number of array elements to be stored
	int n;
	printf("Enter number of array elements : ");
	scanf("%d", &n);
	
	// read n number of array elements one by one
	int i, a[n];
	printf("Enter %d number of elements one by one : \n", n);
	for (i = 0; i < n; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	
	// now sort the array using the bubble sort
	int j, temp;
	for (i = 0; i < n-1; i++) {
		for (j = i+1; j < n; j++) {
			if (a[i] > a[j]) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	
	// print the sorted array
	printf("After sorting the array : \n");
	for (i = 0; i < n; i++) {
		printf("a[%d] = %d\n", i, a[i]);
	}
	
	// read the key element and the position to be inserted at
	int key, pos;
	printf("Enter key element to be inserted : ");
	scanf("%d", &key);
	
	// now move the array elements to the right side
	// from the appropriate position where the element needs to be inserted
	for (i = 0; i < n; i++) {
		if (a[i] > key) {
			for (j = n-1; j >= i; j--) {
				a[j+1] = a[j];
			}
			a[i] = key;
			break;
		}
	}
	
	// increase the value of n as the size of array element is increased by one.
	n++;
	
	// print the final array
	for (i = 0; i < n; i++) {
		printf("a[%d] = %d\n", i, a[i]);
	}
	
	return 0;
}
