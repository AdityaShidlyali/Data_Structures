// Author : Aditya Shidlyali

// Program to find transpose of the matrix

#include <stdio.h>

int main() {
	
	// read the dimension of the matrix
	int n;
	printf("Enter dimension of the matrix : ");
	scanf("%d", &n);
	
	// now read n*n matrix elements
	printf("Enter %d number of elements : \n", n*n);
	int i, j, a[n][n];
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
	
	// print the entered matrix by user
	printf("\nYour entered matrix is : \n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("a[%d][%d] = %d\t", i, j, a[i][j]);
		}
		printf("\n");
	}
	
	// now define 't' array of dimension and store the transpose of the matrix 'a'
	int t[n][n];
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			t[i][j] = a[j][i];
		}
	}
	
	// now print the final array t
	printf("\nTranspose of matrix is : \n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d\t", t[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
