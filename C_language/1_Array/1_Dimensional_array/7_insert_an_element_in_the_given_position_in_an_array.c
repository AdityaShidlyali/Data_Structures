// Author : Aditya Shidlyali

// insert an element at the given position in an array

#include <stdio.h>

int main() {
	
	// read the number of array elements
	int n;
	printf("Enter number of array elements : ");
	scanf("%d", &n);
	
	// read n number of array elements one by one
	int i, a[n+1]; // n+1 so as to insert a new element we need one extra space
	printf("Enter %d number of elements one by one : \n", n);
	for (i = 0; i < n; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	
	// read the postion and the number to be inserted in array
	int pos, key;
	printf("Enter number to be inserted : ");
	scanf("%d", &key);
	printf("Enter position to insert : ");
	scanf("%d", &pos);
	
	if (pos < n && pos >= 0) {
		
		// before inserting element put all the elements to the right side of the from the
		// position to the last position of the array
		for (i = n-1; i >= pos; i--) {
			a[i+1] = a[i];
		}
	
		// now insert the desired element at the specified position
		// and increase the n by 1 as the array size is turned to n+1 after inserting the element
		a[pos] = key;
		n++;
	
		// print the new array after inserting the element
		for (i = 0; i < n; i++) {
			printf("a[%d] = %d\n", i, a[i]);
		}
		
	} else {
		printf("\nPlease enter valid position and try again");
	}
	
	return 0;
}
