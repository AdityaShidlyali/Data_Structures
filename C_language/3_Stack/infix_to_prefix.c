// Author : Aditya Shidlyali

// Program to convert infix to prefix expression

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 30

char stack[MAX];
int top = -1;

char revstr[MAX];
char postfixexp[MAX];

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

void reverseString(char str[]) {

    int i = 0, j = 0;
    int len = strlen(str);
    j = len - 1;

    while (j >= 0) {

        if (str[i] == '(') {

            revstr[i] = ')';

        } else if (str[i] == ')') {

            revstr[i] = '(';

        } else {

            revstr[i] = str[j];

        }

        i++;
        j--;
    }

    revstr[i] = '\0';
}

int priority(char item) {

    if (item == '(') {

        return 0;

    } else if (item == '+' || item == '-') {

        return 1;

    } else if (item == '*' || item == '/') {

        return 2;

    }

}

void postfixConversion(char str[]) {

    int i = 0, j = 0;
    char temp;

    while (str[i]) {

        if (isalnum(str[i])) {

            postfixexp[j] = str[i];
            j++;

        } else if (str[i] == '(') {

            push(str[i]);

        } else if (str[i] == ')') {

            while (temp = pop() != '(') {

                postfixexp[j] = temp;
                j++;

            }

        } else {

            while (top > -1 && priority(stack[top]) >= priority(str[i])) {

                postfixexp[j] = pop();
                j++;

            }

            push(str[i]);
        }

        i++;
    }

    while (top != -1) {

        postfixexp[j] = pop();
        j++;

    }

    postfixexp[j] = '\0';
}

int main() {

    char infix[MAX];

    printf("Enter an expression : ");
    scanf("%s", infix);

    reverseString(infix);

    postfixConversion(revstr);

    reverseString(postfixexp);

    printf("%s", revstr);

    return 0;
}