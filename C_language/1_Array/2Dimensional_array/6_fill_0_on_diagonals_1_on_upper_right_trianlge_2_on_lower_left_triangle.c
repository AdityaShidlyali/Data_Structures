// Author : Aditya Shidlyali

// Program to fill 0 on diagonal elements, 1 on upper right triangle and 2 on lower left trianlge of the matrix

#include <stdio.h>

int main() {
	
	// read the dimension of the triangle
	int r, c;
	printf("Enter number of rows : ");
	scanf("%d", &r);
	printf("Enter number of columns : ");
	scanf("%d", &c);
	
	// store the values accordingly
	int a[r][c], i, j;
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			if (i == j) {
				a[i][j] = 0;
			} else if (i < j) {
				a[i][j] = 1;
			} else {
				a[i][j] = 2;
			}
		}
	}
	
	// print the final array
	printf("The final array is : \n");
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
