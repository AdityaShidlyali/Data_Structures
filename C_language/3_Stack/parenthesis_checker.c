// Author : Aditya Shidlyali

// Program for parenthesis checker

#include <stdio.h>

#define MAX 10

char stack[MAX];
int top = -1;

void push(char item) {
    if (top == (MAX-1)) {
        printf("\nStack Overflowing");
    } else {
        top = top + 1;
        stack[top] = item;
    }
}

char pop() {
    if (top == -1) {
        printf("\nStack Underflowing");
    } else {
        return stack[top--];
    }
}

int main() {

    printf("Enter the brackets : ");
    char str[MAX];
    scanf("%s", str);

    int flag = 1;

    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            push(str[i]);
        }

        if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (top == -1) {
                flag = 0;
            } else {
                char temp = pop();
                if (str[i] == ')' && (temp == '{' || temp == '[')) {
                    flag = 0;
                }
                
                if (str[i] == '}' && (temp == '(' || temp == '[')) {
                    flag = 0;
                }
                
                if (str[i] == ']' && (temp == '(' || temp == '{')) {
                    flag = 0;
                }
            }
        }
    }

    if(top >= 0) {
        flag = 0;
    }

    if (flag == 1) {
        printf("Valid Expression");
    } else {
        printf("Invalid Expression");
    }

    return 0;
}