// Author : Aditya Shidlyali

// Program to read and rotate the matrix of n dimension

#include <stdio.h>

int main() {
	
	// read the dimension of the matrix
	int n;
	printf("Enter dimension of the matrix : ");
	scanf("%d", &n);
	
	// read n*n number of array elements
	int a[n][n], i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
	
	// perform the array rotation
	
	
	// now print the final result
	
	
	return 0;
}
