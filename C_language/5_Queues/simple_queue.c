// Author : Aditya Shidlyali

// Program to implement the operations on simple queue

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void insert();
void delete();
void peek();
void display();

int front = -1, rear = -1;

int queue[MAX];

int main() {

    printf("\nQueue operations\n");
    printf("1. Insert\n2. Delete\n3. Peek\n4. Display\n5. Exit");

    int option, val;
    while (1) {
        printf("\nEnter your option : ");
        scanf("%d", &option);

        switch (option) {
            case 1: insert();
            break;

            case 2: delete();
            break;

            case 3: peek();
            break;

            case 4: display();
            break;

            case 5: exit(0);

            default: printf("Enter valid option !");
            break;
        }
    }

    return 0;
}

void insert() {
    
    if (rear == MAX-1) {

        printf("The queue is overflowing !");

    } else {

        if (front == -1) {
            front = 0;
        }

        printf("Enter item to insert into queue : ");
        int item;
        scanf("%d", &item);
        queue[++rear] = item;
    }
}

void delete() {

    if (front == -1 || front > rear) {

        printf("The queue is overflowing !");

    } else {

        if (front == rear) {
            printf("\n%d deleted\n", queue[front++]);
            printf("The queue is underflowing");
        } else {
            printf("\n%d deleted\n", queue[front++]);
        }
    }
}

void peek() {
    
    if (front == -1 || front > rear) {
        
        printf("The queue is empty"); 

    } else {

        printf("The peek element is : %d", queue[front]);

    }
}

void display() {

    if (front == -1 || front > rear) {

        printf("The queue is empty");

    } else {

        int i;
        for (i = front; i <= rear; i++) {

            printf("%d ", queue[i]);

        }
    }
}