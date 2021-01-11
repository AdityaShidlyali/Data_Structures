// Author : Aditya Shidlyali

// Program to convert infix to postfix expression

#include <stdio.h>
#include <ctype.h>

#define MAX 30

char stack[MAX];
int top = -1;

void push(char item) {
    if (top == (MAX-1)) {
        printf("Stack is overflowing");
    } else {
        stack[++top] = item;
    }
}

char pop() {

    if (top == -1) {
        printf("Stack is underflowing"); 
    } else {
        return stack[top--];
    }
    
}

int priority(char item) {

    if (item == '(') {
        return 0;
    }

    if(item == '+' || item == '-') {
        return 1;
    }

    if (item == '*' || item == '/') {
        return 2;
    }

    return 0;
}

void postfixConvert(char str[]) {

    int i = 0;
    char temp;
    
    printf("The equivalent postfix expression is : ");

    while (str[i]) {

        if (isalnum(str[i])) {

            printf("%c", str[i]);

        } else if (str[i] == '(') {

            push(str[i]);

        } else if (str[i] == ')') {

            while (temp = pop() != '(') {
                printf("%c", temp);
            }

        } else {

            while (priority(stack[top]) >= priority(str[i])) {
                printf("%c", pop());
            }

            push(str[i]);
        }

        i++;
    }

    while (top != -1) {
        printf("%c", pop());
    }
}

int main() {

    printf("Enter an expression : ");
    char str[MAX];
    scanf("%s", str);
    postfixConvert(str);
    return 0;

}