#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int priority;
    struct node *next;
};

struct node *getNode(int dat, int pri) {

    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode -> data = dat;
    newNode -> priority = pri;
    newNode -> next = NULL;

    return newNode;
}

struct node *insert(struct node *);
struct node *delete(struct node *);
struct node *display(struct node *);

int main() {

    int option;

    struct node *head = NULL;

    do {

        printf("\n---PRIORITY QUEUE---\n");
        printf("1. INSERT ");
        printf("2. DELETE ");
        printf("3. DISPLAY ");
        printf("4. EXIT");
        printf("\n\nEnter your option : ");
        scanf("%d", &option);

        switch (option) {

            case 1: head = insert(head);
            break;
            case 2: head = delete(head);
            break;
            case 3: head = display(head);
            break;
            case 4: exit(0);
            default:printf("\nEnter valid option !");
            break;

        }

    } while (1);

    return 0;
}

struct node *insert(struct node *head) {

    int dat;
    printf("\nEnter the data to insert : ");
    scanf("%d", &dat);
    
    int pri;
    printf("\nEnter the priority : ");
    scanf("%d", &pri);

    struct node *ptr = head;
    struct node *prePtr = ptr;
    struct node *newNode = getNode(dat, pri);

    if (head == NULL) {

        head = newNode;

    } else if (head -> priority > pri) {

        head = newNode;
        newNode -> next = ptr;

    } else {

        while (ptr -> next != NULL) {

            if (ptr -> priority > pri) {
                break;
            }

            prePtr = ptr;

            ptr = ptr -> next;
        }

        newNode -> next = ptr;
        prePtr -> next = newNode;

    }

    return head;

}

struct node *delete(struct node *head) {

    if (head == NULL) {

        printf("\nPriority queue is empty !\n");
    } else {

        struct node *ptr = head;
        printf("\nThe element %d has deleted successfully\n", ptr -> data);
        head = head -> next;
        free(ptr);
    }

    return head;
}

struct node *display(struct node *head) {

    if (head == NULL) {
        printf("\nPriority queue is empty !\n");
    } else {
        struct node *ptr = head;
        while (ptr != NULL) {
            printf("%d => ", ptr -> data);
            ptr = ptr -> next;
        }
    }

    return head;
}