// Author : Aditya Shidlyali

// Program to read and change the value of the 

#include <stdio.h>

int main() {
	
	// read number of elements
	int n;
	printf("Enter number of elements : ");
	scanf("%d", &n);
	
	// read n number of elements one by one
	int i, a[n];
	for (i = 0; i < n; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	
	// read the position by user to change the element in the array
	int pos, key;
	printf("Enter position to change the element : ");
	scanf("%d", &pos);	
	if (pos < n && pos >= 0) {
		
		// if the user enters the correct position to change 
		// then only read the key element to replace the value
		printf("Enter key element to change its value : ");
		scanf("%d", &key);
		
		// now define the pointer of the type of the array and change the value
		int *ptr = a;
		*(ptr + (int)pos) = key;
		
		// now print the final array after changing the array element
		printf("The final array after chainging is : \n");
		for (i = 0; i < n; i++) {
			printf("a[%d] = %d\n", i, a[i]);
		}
	} else {
		printf("Enter correct valid value of position and try again!");
	}
	
	return 0;
}
