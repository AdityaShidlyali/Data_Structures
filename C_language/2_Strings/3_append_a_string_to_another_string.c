// Author : Aditya Shidlyali

// Program to append a string from another string

#include <stdio.h>

int main() {
	
	// read first string
	char str1[20];
	printf("Enter string 1 : ");
	scanf("%s", str1);
	
	// read second string
	char str2[10];
	printf("Enter string 2 : ");
	scanf("%s", str2);
	
	// perform the appending of the string
	int i = 0;
	while (str1[i] != '\0') {
		i++;
	}
	int j = 0;
	while (str2[j] != '\0') {
		str1[i] = str2[j];
		j++;
		i++;
	}
	
	// now print the final string after appending
	printf("The final appended string is : %s", str1);
	
	return 0;
}
