// Author : Aditya Shidlyali

// Program to implement the PUSH POP and PEEK operations of the stack using array

#include <stdio.h>
#include <stdlib.h>

// define the maximum size of the stack
#define MAX_SIZE 4

// define the stack array and TOP variable
int TOP = -1;
int STACK[MAX_SIZE];

// define the functions used in the program
void PUSH();
void POP();
void PEEK();
void DISPLAY();

int main() {
    // display stack operation and read the option numbers by users
    int option;
    do {
        printf("\n---Stack Operations---\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");
        printf("Enter your option : ");
        scanf("%d",&option);

        // perform the stack operation based on the user option
        switch (option) {
            case 1: PUSH();
            break;
            case 2: POP();
            break;
            case 3: PEEK();
            break;
            case 4: DISPLAY();
            break;
            case 5: exit(0);
            break;
            default: printf("Enter valid choice !\n");
        }

    } while (1);

    return 0;
}

// function for PUSH operation
void PUSH() {
    if (TOP < MAX_SIZE) {
        printf("\nEnter an item to push : ");
        int item;
        scanf("%d", &item);

        TOP++;
        STACK[TOP] = item;
    }
    else {
        printf("\nThe stack is OVERFLOWING !\n");
    }
}

// function for POP operation
void POP() {
    if (TOP >= 0){
        printf("\nThe item %d is popped successfully\n", STACK[TOP]);
        TOP--;
    }
    else {
        printf("\nThe stack is UNDERFLOWING !\n");
    }
}

// function for PEEK operation
void PEEK() {
    if (TOP >= 0) {
        printf("\nThe peek item is %d\n", STACK[TOP]);
    }
    else {
        printf("\nThe stack is empty !\n");
    }
}

// function to display all the elements of the stack
void DISPLAY() {
    if (TOP >= 0) {
        printf("\nThe stack is : \n");
        int i;
        for (i = TOP; i >= 0; i--) {
            printf("STACK[%d] = %d\n", i, STACK[i]);
        }
    }
    else {
        printf("\nThe stack is empty !\n");
    }
}