// Author : Aditya Shidlyali

// Program to find the multiplication of two matrices

#include <stdio.h>

int main() {
	
	// read the dimension of first matrix :
	int row1, col1;
	printf("Enter number of rows for matrix A : ");
	scanf("%d", &row1);
	printf("Enter number of columns for matrix A : ");
	scanf("%d", &col1);
	
	// read the dimension of second matrix :
	int row2, col2;
	printf("Enter number of rows for matrix B : ");
	scanf("%d", &row2);
	printf("Enter number of columns for matrix B : ");
	scanf("%d", &col2);
	
	// now check whether the number of columns of first matrix is equal to
	// number of rows of second matrix
	if (col1 != row2) {
		printf("Enter proper dimensions of the both the matrix and try again !");
	} else {
		
		// define 'a' matrix and read the elements for matrix A
		printf("Enter %d number of elements for matrix A : \n", row1*col1);
		int i, j, a[row1][col1];
		for (i = 0; i < row1; i++) {
			for (j = 0; j < col1; j++) {
				printf("a[%d][%d] = ", i, j);
				scanf("%d", &a[i][j]);
			}
		}
		
		// define 'b' matrix and read the elements for matrix B
		int b[row2][col2];
		printf("Enter %d number of elements for matrix B : \n", row2*col2);
		for (i = 0; i < row2; i++) {
			for (j = 0; j < col2; j++) {
				printf("a[%d][%d] = ", i, j);
				scanf("%d", &b[i][j]);
			}
		}
		
		// display matrix A
		printf("\nMatrix A is :\n");
		for (i = 0; i < row1; i++) {
			for (j = 0; j < col1; j++) {
				printf("%d\t", a[i][j]);
			}
			printf("\n");
		}
		
		// display matrix B
		printf("\nMatrix B is :\n");
		for (i = 0; i < row1; i++) {
			for (j = 0; j < col1; j++) {
				printf("%d\t", b[i][j]);
			}
			printf("\n");
		}
		
		// now define the matrix 'c' to store the multiplication result
		int c[row2][col1], k;
		for (i = 0; i < row1; i++) {
			for (j = 0; j < col1; j++) {
				c[i][j] = 0;
				for (k = 0; k < col1; k++) {
					c[i][j] += a[i][k] * b[k][j];
				}
			}
		}
		
		// now print the final array 'c' which contains the multiplication of
		// the two matrices
		printf("\nThe result is : \n");
		for (i = 0; i < row1; i++) {
			for (j = 0; j < col2; j++) {
				printf("%d\t", c[i][j]);
			}
			printf("\n");
		}
	}
	
	return 0;
}
