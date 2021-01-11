// Author : Aditya Shidlyali

// Program to read and find the length of the string

#include <stdio.h>

int main() {
	
	// define and read the string
	char str[10];
	printf("Enter a string : ");
	scanf("%s", str);
	
	// define variable of 'len' and initialise it to zero
	int len = 0, i = 0;
	while (str[i] != '\0') {
		len++;
		i++;
	}
	
	// now print the lenght of the string
	printf("The length of the string is : %d", len);
	
	return 0;
}
