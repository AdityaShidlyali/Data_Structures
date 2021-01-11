// Author : Aditya Shidlyali

// find whether the array contain the duplicate numbers or not

#include <stdio.h>

int main() {
	
	// read the number of elements
	int n;
	printf("Enter number of array elements : ");
	scanf("%d", &n);
	
	// read the n number of elements one by one
	int a[n], i;
	printf("Enter %d number of elements one by one : \n", n);
	for (i = 0; i < n; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	
	// to keep the track of the repeated element we take the flag as 0 initially
	// if flag turns to be 1 then the array contains the duplicate elements
	int flag = 0, j;
	for (i = 0; i < n; i++) {
		for (j = i+1; j < n; j++) {
			if (a[i] == a[j] && i != j) {
				flag = 1;
				printf("\nDuplicate numbers found at locations %d and %d", i, j);
			}
		}
	}
	
	// print according to change in flag variable
	if (flag == 0) {
		printf("\nThe array doesn\'t contain duplicate elements");
	} else {
		printf("\nThe array contains duplicate numbers");
	}
	
	return 0;
}
