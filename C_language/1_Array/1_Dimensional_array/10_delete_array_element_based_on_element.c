// Author : Aditya Shidlyali

// Deleting the array element based on the position

#include <stdio.h>

int main() {
	
	// read the number of elements
	int n;
	printf("Enter number of elements : ");
	scanf("%d", &n);
	
	// read n number of element one by one
	int i, a[n];
	printf("Enter %d number of elements one by one : \n", n);
	for (i = 0; i < n; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	
	// read the key element to be deleted in the array
	printf("Enter element to be deleted : ");
	int key;
	scanf("%d", &key);
	
	// now perfrom the deletion operation to the array
	int flag = 0; // flag to check whether the element exists or not
	for (i = 0; i < n; i++) {
		if (a[i] == key) {
			flag = 1; // change the flag variable as we have encountered the right element to be deleted from array which exist in array
			int j;
			for (j = i; j < n; j++) {
				a[j] = a[j+1];
			}
			
			// decrease the size of the array by one as it has reduced by one element
			n--;
			
			// now break the outer loop as we have found the element and deleted the element successfully
			break;
		}
	}
	
	if (flag == 0) {
		
		// if the element is not found in the array entered by the user then print
		// the warning message.
		printf("Entered element does not exist");
	} else {
		
		// if the element found the print the final array
		printf("Final array is : \n");
		for (i = 0; i < n; i++) {
			printf("a[%d] = %d\n", i, a[i]);
		}
	}
	
	return 0;
}
