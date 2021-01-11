// Author : Aditya Shidlyali

// Program to find the addition of two matrix

#include <stdio.h>

int main() {
	
	// read the dimension of the matrix
	int row, col;
	printf("Enter number of rows : ");
	scanf("%d", &row);
	printf("Enter number of columns : ");
	scanf("%d", &col);
	
	// now read row*col number of elements for the matrix A :
	printf("Enter %d number of elements for matrix A : \n", row*col);
	int a[row][col], i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
	
	// now read row*col number of elements for the matrix B :
	printf("Enter %d number of elements for matrix B : \n", row*col);
	int b[row][col];
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("b[%d][%d] = ", i, j);
			scanf("%d", &b[i][j]);
		}
	}
	
	// now print the matrix a :
	printf("\nThe matrix A : \n");
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
	
	// now print the matrix b :
	printf("\nThe matrix B : \n");
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
	
	// now perform the addition and store the result in array C :
	int c[row][col];
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			c[i][j] = a[i][j] + b[i][j];
		}
	}
	
	// now print the addition of the two arrays which is array C :
	printf("\nThe addition of two matrices is : \n");
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%d\t", c[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
