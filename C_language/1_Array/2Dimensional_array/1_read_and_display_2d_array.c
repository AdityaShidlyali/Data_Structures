// Author : Aditya Shidlyali

// Program to read and display 2D array in form of matrix

#include <stdio.h>

int main() {
	
	// read the number of rows and columns of the 2D array
	int row, col;
	printf("Enter number of rows : ");
	scanf("%d", &row);
	printf("Enter number of columns : ");
	scanf("%d", &col);
	
	// now read row * col size 2d matrix array
	int i, j, a[row][col];
	printf("Enter %d number of elements : \n", row*col);
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
	
	// now print the 2D array in the form of matrix
	printf("\nThe final 2D matrix is : \n");
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("a[%d][%d] = %d\t", i, j, a[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
