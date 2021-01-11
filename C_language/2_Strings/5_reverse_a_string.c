// Author : Aditya Shidlyali

// Program to reverse a string

#include <stdio.h>
// import the string.h library to find the lenght of the string
#include <string.h>

int main() {
	
	// read a string
	char str[10];
	printf("Enter a string : ");
	scanf("%s", str);
	
	// now perform the reverse operation
	char revStr[10];
	int i = strlen(str) - 1, j = 0;
	while(str[i] != '\0') {
		revStr[j] = str[i];
		i--;
		j++;
	}
	
	// print the final string
	printf("Reverse of the string is : %s", revStr);
	
	return 0;
}
