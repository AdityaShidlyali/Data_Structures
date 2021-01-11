#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int dequeue[MAX];

int front = -1, rear = -1;

void inputDequeue();
void outputDequeue();
void insertFront();
void insertRear();
void deleteFront();
void deleteRear();
void display();

int main() {

    int option;
    printf("\n---DEQUEUE OPERATIONS---\n");
    printf("1. Input restricted queue");
    printf("\n2. Output restricted queue");
    printf("\n\nEnter your option : ");
    scanf("%d", &option);

    switch(option) {
        case 1: inputDequeue();
        break;
        case 2: outputDequeue();
        break;
        default: printf("Enter valid option !");
        break;
    }

    return 0;
}

void inputDequeue() {
    int option;
    do {

        printf("\n---INPUT RESTRICTED QUEUE---\n");
        printf("1. Insert at rear");
        printf("\n2. Delete from rear");
        printf("\n3. Delete from front");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\n\nEnter your option : ");
        scanf("%d", &option);

        switch(option) {
            case 1: insertRear();
            break;
            case 2: deleteRear();
            break;
            case 3: deleteFront();
            break;
            case 4: display();
            break;
            case 5: exit(0);
            default: printf("Enter the valid choice !");
        }

    } while (1);

}

void outputDequeue() {
    int option;
    do {

        printf("\n---OUTPUT RESTRICTED QUEUE---\n");
        printf("1. Insert at rear");
        printf("\n2. Insert at front");
        printf("\n3. Delete from front");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\n\nEnter your option : ");
        scanf("%d", &option);

        switch(option) {
            case 1: insertRear();
            break;
            case 2: insertFront();
            break;
            case 3: deleteFront();
            break;
            case 4: display();
            break;
            case 5: exit(0);
            default: printf("Enter the valid choice !");
        }

    } while (1);

}

void insertRear() {

    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("\n\nQueue is overflowing\n");
        return;
    }

    int data;
    printf("\n\nEnter data to insert : ");
    scanf("%d", &data);

    if (rear == -1) {
        front = 0;
        rear = 0;
    } else {
        if (rear == MAX - 1) {
            rear = 0;
        } else {
            rear++;
        }
    }

    dequeue[rear] = data;
    printf("The element %d added successfully", dequeue[rear]);
}

void insertFront() {

    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("\n\nQueue is overflowing\n");
        return;
    }

    int data;
    printf("\n\nEnter data to insert : ");
    scanf("%d", &data);

    if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        if (front == 0) {
            front = MAX - 1;
        } else {
            front--;
        }
    }

    dequeue[front] = data;
    printf("The element %d added successfully", dequeue[front]);
}

void deleteRear() {

    if (rear == -1) {
        printf("\n\nThe queue is underflowing\n");
        return;
    }

    printf("\nThe element %d is deleted successfully\n", dequeue[rear]);

    if (rear == front) {
        rear = -1;
        front = -1;
    } else {
        if (rear == 0) {
            rear = MAX - 1;
        } else {
            rear--;
        }
    }
}

void deleteFront() {

    if (front == -1) {
        printf("\n\nThe queue is underflowing\n");
        return;
    }

    printf("\nThe element %d is deleted successfully\n", dequeue[front]);

    if (rear == front) {
        rear = -1;
        front = -1;
    } else {
        if (front == MAX - 1) {
            front = 0;
        } else {
            front++;
        }
    }
}

void display() {
    
    int tempRear = rear, tempFront = front;

    if (tempFront == -1) {
        printf("\nThe queue is empty\n");
        return;
    }

    if (tempFront <= tempRear) {
        while (tempFront <= tempRear) {
            printf("%d  ", dequeue[tempFront]);
            tempFront++;
        }
    } else {
        while (tempFront <= MAX - 1) {
            printf("%d  ", dequeue[tempFront]);
            tempFront++;
        }

        tempFront = 0;

        while (tempFront <= tempRear) {
            printf("%d  ", dequeue[tempFront]);
            tempFront++;
        }
    }
}