// Author : Aditya Shidlyali

// Program to delete an array elements from already sorted array.

#include <stdio.h>

int main() {
	
	// read number of elements
	int n;
	printf("Enter number of elements : ");
	scanf("%d", &n);
	
	// read n number of elements one by one in ascending order
	printf("Enter %d number of array elements one by one in ascending order : \n", n);
	int i, a[n];
	for (i = 0; i < n; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	
	// read the key element to be deleted from the array
	printf("Enter element to be deleted : ");
	int key;
	scanf("%d", &key);
	
	// perform the deletion operation
	int flag = 0; // flag variable to check whether the elment exists or not
	for (i = 0; i < n; i++) {
		if (a[i] == key) {
			flag = 1; // change the flag variable as we have encountered the right element to be deleted from array which exist in array
			int j;
			for (j = i; j < n; j++) {
				a[j] = a[j+1];
			}
			
			// decrease the size of the array as we have remove the element from the array
			n--;
			
			// now break the outer loop as we have successfully deleted the array element
			break;
		}
	}
	
	// check if the element is present or not and print the result accordingly
	// by using flag variable
	if (flag == 0) {
		printf("Entred key element is not present in the array element !");
	} else {
		// print the final array output
		printf("Final array after deletion is : \n");
		for (i = 0; i < n; i++) {
			printf("a[%d] = %d\n", i, a[i]);
		}
	}
	
	return 0;
}
