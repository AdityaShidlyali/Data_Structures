// Author : Aditya Shidlyali

// program to toggle lowercase and uppercase letters in a string

#include <stdio.h>

int main() {
	
	// read the string
	char str[10];
	printf("Enter a string : ");
	scanf("%s", str);
	
	// now perform the toggling
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] = str[i] - 32;
		} else {
			str[i] = str[i] + 32;
		}
		i++;
	}
	
	// now print the final string
	printf("The final string is : %s", str);
	
	return 0;
}
