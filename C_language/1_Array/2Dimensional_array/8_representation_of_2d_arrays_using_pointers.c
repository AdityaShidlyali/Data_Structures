// Author : Aditya Shidlyali

// Program to read and display 2D matrix using pointers

#include <stdio.h>

int main() {
	
	// read the dimension of the matrix
	int n;
	printf("Enter dimension of the matrix : ");
	scanf("%d", &n);
	
	// read n*n number of elements for the matrix
	printf("Enter %d number of elements one by one : \n", n*n);
	int i, j, a[n][n];
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
	
	// now print the 2d array in the form of matrix using pointers
	// must take care of the round brackets.
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("a[%d][%d] = %d\t", i, j, (*(*(a + i)) + j));
		}
		printf("\n");
	}
	
	return 0;
}
