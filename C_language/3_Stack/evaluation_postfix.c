// Author : Aditya Shidlyali

// Program to evaluate the postfix expression using stack

#include <stdio.h>
#include <ctype.h>

#define MAX 30

float stack[MAX];
int top = -1;

void push(float item) {
    if (top == MAX-1) {
        printf("Stack is Overflowing");
    } else {
        stack[++top] = item;
    }
}

float pop() {
    if (top == -1) {
        printf("The stack is underflowing");
    } else {
        return stack[top--];
    }
}

int main() {

    printf("Enter the valid postfix expression : ");
    char str[MAX];
    scanf("%s", str);

    float total = 0, operator1, operator2;

    int i = 0;

    while (str[i]) {

        if (isdigit(str[i])) {
            push((float) (str[i] - '0'));
        } else {

            operator1 = pop();
            operator2 = pop();

            switch(str[i]) {
                case '+': total = operator2 + operator1;
                break;
                case '-': total = operator2 - operator1;
                break;
                case '*': total = operator2 * operator1;
                break;
                case '/': total = operator2 / operator1;
                break;
            }

            push(total);
        }

        i++;
    }

    printf("%.2f", pop());

    return 0;
}