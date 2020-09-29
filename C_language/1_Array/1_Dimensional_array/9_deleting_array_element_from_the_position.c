// Author : Aditya Shidlyali

// program to delete the array element from the position

#include <stdio.h>

int main() {

	// read number of elements to be inserted in array
	int n;
	printf("Enter number of elements : ");
	scanf("%d", &n);

	// read n number of array elements one by one
	int a[n], i;
	printf("Enter %d number of elements one by one : \n", n);
	for (i = 0; i < n; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}

	// read the postion to be deleted in array.
	int pos;
	printf("Enter position to delete element from the array : ");
	scanf("%d", &pos);

	if (pos < n && pos >= 0) {
		// from the position entered by the user to end of the array
		// push the elements to left side of the array.
		int i;
		for (i = pos - 1; i < n - 1; i++) {
			a[i] = a[i + 1];
		}

		// now replace the last number with 0
		a[n - 1] = 0;
		// decrease the n as one of the element got deleted from the array.
		n--;

		// now print the final array
		for (i = 0; i < n; i++) {
			printf("a[%d] = %d\n", i, a[i]);
		}
	}
	else {
		printf("Please enter valid position number and try again");
	}

	return 0;
}
