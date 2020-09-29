// Author : Aditya Shidlyali

// form a number using the numbers of the array

#include <stdio.h>
#include <math.h>

int main() {
	
	// read number of digits
	int numberOfDigits;
	printf("Enter number of digits : ");
	scanf("%d", &numberOfDigits);
	
	// read n number of positions in an array one by one
	int i, a[numberOfDigits];
	for (i = 0; i < numberOfDigits; i++) {
		printf("Number at position %d = ", i+1);
		scanf("%d", &a[i]);
	}
	
	// form the number using power function with increase in the power of i
	int finalNumber = 0;
	for (i = 0; i < numberOfDigits; i++) {
		finalNumber += a[i] * pow(10, i);
	}
	
	// now print the final number
	printf("The desired number is = %d", finalNumber);
	
	return 0;
}
