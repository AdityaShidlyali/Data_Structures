// Author : Aditya Shidlyali

// Program to compare two strings

#include <stdio.h>
// import the string library to find the lenght of the string
#include <string.h>

int main() {
	
	// read first string
	char str1[10];
	printf("Enter first string : ");
	scanf("%s", str1);
	
	// read second string
	char str2[10];
	printf("Enter second string : ");
	scanf("%s", str2);
	
	// find the lenght of each strings and store the lenghts in appropriate variables
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	
	// check whose string is more and less and print the output accordingly
	if (len1 != len2) {
		if (len1 < len2) {
			printf("The lenght of the string 1 is less than the string 2");
		} else {
			printf("The lenght of the string 2 is less than the string 1");
		}
	} else {
		
		// initialise the flag variable to check whether the two of the strings are equal or not
		int flag = 0;
		
		int i = 0;
		while (str1[i] != '\0') {
			if (str1[i] == str2[i]) {
				flag = 1;
			} else {
				flag = 0;
				
				// check if whose character is greater than whom and print the statement accordingly
				if (str1[i] < str2[i]) {
					printf("First string is greater than the second string");
				} else {
					printf("Second string is greater than the first string");
				}
				
				break;
			}
			i++;
		}
		
		// of the flag variable changes then ony print entered two strings are same
		if (flag == 1) {
			printf("Entered two string are same");
		}
	}
	
	return 0;
}
