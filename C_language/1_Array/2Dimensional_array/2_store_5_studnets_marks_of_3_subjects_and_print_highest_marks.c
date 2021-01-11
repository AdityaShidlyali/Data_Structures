// Author : Aditya Shidlyali

// Program to store 5 students marks and print their highest marks in each subjects

#include <stdio.h>

int main() {
	
	// read three subjects marks first
	int a[5][3], i, j;
	for (i = 0; i < 5; i++) {
		printf("\nEnter student %d marks -> \n", i+1);
		for (j = 0; j < 3; j++) {
			printf("Enter subject %d marks : ", j+1);
			scanf("%d", &a[i][j]);
		}
	}
	
	// now print their highest marks subjects
	for (i = 0; i < 5; i++) {
		printf("\nHighest marks obtained by student %d = ", i+1);
		int max_marks = a[i][j];
		for (j = 0; j < 3; j++) {
			if (max_marks < a[i][j]) {
				max_marks = a[i][j];
			}
		}
		
		printf("%d\n", max_marks);
	}
	
	return 0;
	
}
