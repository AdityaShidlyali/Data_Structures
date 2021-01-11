// Author : Aditya Shidlyali

// Program to reverse a string using stack

#include <stdio.h>

#define MAX_SIZE 20

char STACK[MAX_SIZE];
int TOP = -1;

void PUSH(char item) {
    TOP++;
    STACK[TOP] = item;
}

void POP() {
    printf("%c", STACK[TOP]);
    TOP--;
}

int main() {

    char str[20];
    printf("Enter the string to reverse : ");
    scanf("%s", str);

    int i = 0;
    for (i = 0; str[i] != '\0'; i++) {
        PUSH(str[i]);
    }

    for (i = TOP; i >= 0; i--) {
        POP();
    }

    return 0;
}