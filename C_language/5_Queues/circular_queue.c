// Author : Aditya Shidlyali

// Program to implement the operations on circular queue

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void insert();
void delete();
void peek();
void display();

int front = -1, rear = -1;
int queue[MAX];

int main() {

    printf("Queue operations");
    printf("\n1. Insert\n2. Delete\n3. Peek\n4. Display\n5. Exit");

    int option;
    while (1) {

        printf("\nEnter your options : ");
        scanf("%d", &option);
        switch(option) {

            case 1: insert();
            break;
            case 2: delete();
            break;
            case 3: peek();
            break;
            case 4: display();
            break;
            case 5: exit(0);
            default: printf("\nEnter valid option !\n");
            break;
        }
    }

    return 0;
}

void insert() {

    if ((front == 0 && rear == MAX -1) || (front == rear + 1)) {

        printf("\nThe queue is overflowing\n");

    } else if (front == -1 && rear == -1) {

        int item;
        printf("\nEnter the item to insert : ");
        scanf("%d", &item);

        front = 0;
        rear = 0;
        printf("\nThe element %d inserted successfully\n", item);
        queue[rear] = item;

    } else if (front != 0 && rear == MAX -1) {

        int item;
        printf("\nEnter the item to insert : ");
        scanf("%d", &item);

        rear = 0;
        printf("\nThe element %d inserted successfully\n", item);
        queue[rear] = item;

    } else {

        int item;
        printf("\nEnter the item to insert : ");
        scanf("%d", &item);

        printf("\nThe element %d inserted successfully\n", item);
        queue[++rear] = item;

    }
}

void delete() {

    if (front == -1 && rear == -1) {

        printf("The queue is underflowing");

    } else if (front == rear) {

        printf("\nThe element %d is deleted\n", queue[front]);
        printf("The queue is underflowing\n");

        rear = front = -1;

    } else if (front == MAX - 1) {

        printf("The %d is deleted successfully", queue[front]);
        front = 0;

    } else {

        printf("The %d is deleted successfully", queue[front++]);

    }
}

void peek() {

    if (front == -1 && rear == -1) {

        printf("\nThe queue is empty\n");

    } else {

        printf("\nThe peek item is %d\n", queue[front]);

    }
}

void display() {

    if (front == -1 && rear == -1) {

        printf("\nThe queue is empty\n");

    } else {
        
        int i;

        if (front < rear) {

            printf("\nThe queue elements are : \n");

            for (i = front; i <= rear; i++) {
                printf("%d  ", queue[i]);
            }

        } else {

            printf("\nThe queue elements are : \n");

            for (i = front; i < MAX; i++) {
                printf("%d  ", queue[i]);
            }

            for (i = 0; i <= rear; i++) {
                printf("%d  ", queue[i]);
            }
        }
    }
}