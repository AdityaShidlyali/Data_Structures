// Author : Aditya Shidlyali

// Program to implement the operations on circular singly linked list

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *getNode(int item) {
    struct node *newNode = (struct node *) malloc(sizeof(struct node *));

    newNode -> data = item;
    newNode -> next = NULL;

    return newNode;
}

struct node *createLinkedList(struct node *);
struct node *displayLinkedList(struct node *);
struct node *insertBeginning(struct node *);
struct node *insertEnd(struct node *);
struct node *insertAfter(struct node *);
struct node *insertBefore(struct node *);
struct node *deleteBeginning(struct node *);
struct node *deleteEnd(struct node *);
struct node *deleteEntireList(struct node *);
struct node *deleteAfter(struct node *);
struct node *deleteNode(struct node *);
struct node *sortList(struct node *);

int main() {

    struct node *head = NULL;

    int option;

    do {
        printf("\n\n---Linked List operations---\n");
        printf("1. Create a linked list\n");
        printf("2. Display linked list\n");
        printf("3. Insert at beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert after\n");
        printf("6. Insert before\n");
        printf("7. Delete beginning\n");
        printf("8. Delete end\n");
        printf("9. Delete entire list\n");
        printf("10. Delete after\n");
        printf("11. Delete node\n");
        printf("12. Sort the list\n");

        printf("13. Exit\n");

        printf("\nEnter your option : ");

        scanf("%d", &option);

        switch (option) {
            case 1: head = createLinkedList(head);
            break;
            case 2: head = displayLinkedList(head);
            break;
            case 3: head = insertBeginning(head);
            break;
            case 4: head = insertEnd(head);
            break;
            case 5: head = insertAfter(head);
            break;
            case 6: head = insertBefore(head);
            break;
            case 7: head = deleteBeginning(head);
            break;
            case 8: head = deleteEnd(head);
            break;
            case 9: head = deleteEntireList(head);
            break;
            case 10: head = deleteAfter(head);
            break;
            case 11: head = deleteNode(head);
            break;
            case 12: head = sortList(head);
            break;
            case 13: exit(0);
            break;
            default: printf("\nEnter valid option !\n");
            break;
        }

    } while (1);

    return 0;
}

struct node *createLinkedList(struct node *head) {
    struct node *ptr = head, *newNode;

    ptr = head;

    int item;
    printf("Enter -1 to stop entering the data\n");
    printf("Enter data to insert into the linkedlist : ");
    scanf("%d", &item);

    while (item != -1) {

        newNode = getNode(item);

        if (head == NULL) {
            newNode -> next = newNode;

            head = newNode;

        } else {

            ptr = head;

            while (ptr -> next != head) {
                ptr = ptr -> next;
            }

            ptr -> next = newNode;

            newNode -> next = head;
        }

        printf("Enter -1 to stop entering the data\n");
        printf("Enter data to insert into the linkedlist : ");
        scanf("%d", &item);
    }

    return head;
}

struct node *displayLinkedList(struct node *head) {
    struct node *ptr;

    ptr = head;

    while (ptr -> next != head) {
        printf("%d => ", ptr -> data);
        ptr = ptr -> next;
    }

    printf("%d", ptr -> data);

    return head;
}

struct node *insertBeginning(struct node *head) {

    struct node *ptr = head;

    int item;
    printf("Enter data to insert : ");
    scanf("%d", &item);

    struct node *newNode = getNode(item);

    while (ptr -> next != head) {
        ptr = ptr -> next;
    }

    ptr -> next = newNode;

    newNode -> next = head;

    head = newNode;

    return head;
}

struct node *insertEnd(struct node *head) {

    struct node *ptr = head;

    int item;
    printf("Enter data to insert : ");
    scanf("%d", &item);

    struct node *newNode = getNode(item);

    while (ptr -> next != head) {
        ptr = ptr -> next;
    }

    ptr -> next = newNode;

    newNode -> next = head;

    return head;
}

struct node *insertAfter(struct node *head) {
    struct node *ptr = head;
    struct node *prePtr = ptr;

    int item;
    printf("Enter data to insert : ");
    scanf("%d", &item);

    int key;
    printf("Enter key for reference to insert the data after : ");
    scanf("%d", &key);

    struct node *newNode = getNode(item);

    while (prePtr -> data != key) {
        prePtr = ptr;
        ptr = ptr -> next;
    }

    prePtr -> next = newNode;

    newNode -> next = ptr;

    return head;
}

struct node *insertBefore(struct node *head) {

    struct node *ptr = head;
    struct node *prePtr = ptr;

    int item;
    printf("Enter data to insert : ");
    scanf("%d", &item);

    struct node *newNode = getNode(item);

    int key;
    printf("Enter key with reference the data to insert before : ");
    scanf("%d", &key);

    while (ptr -> data != key) {
        prePtr = ptr;
        ptr = ptr -> next;
    }

    prePtr -> next = newNode;

    newNode -> next = ptr;

    return head;
}

struct node *deleteBeginning(struct node *head) {

    struct node *ptr = head;

    while (ptr -> next != head) {
        ptr = ptr -> next;
    }

    ptr -> next = head -> next;

    free(head);

    head = ptr -> next;

    return head;
}

struct node *deleteEnd(struct node *head) {

    struct node *ptr = head;

    struct node *prePtr = ptr;

    while (ptr -> next != head) {
        prePtr = ptr;
        ptr = ptr -> next;
    }

    prePtr -> next = ptr -> next;

    free(ptr);

    return head;
}

struct node *deleteEntireList(struct node *head) {

    struct node *ptr = head;

    while (ptr -> next != head) {
        head = deleteBeginning(head);
    }

    free (head);

    return head;
}

struct node *deleteAfter(struct node *head) {

    struct node *ptr = head;

    struct node *prePtr = ptr;

    int key;
    printf("Enter key with reference with which the element has to be deleted after : ");
    scanf("%d", &key);

    while (prePtr -> data != key) {
        prePtr = ptr;
        ptr = ptr -> next;
    }

    prePtr -> next = ptr -> next;

    free(ptr);

    return head;
}

struct node *deleteNode(struct node *head) {

    struct node *ptr = head;

    int key;
    printf("Enter value of the node to delete : ");
    scanf("%d", &key);

    struct node *prePtr = ptr;

    while (ptr -> data != key) {
        prePtr = ptr;
        ptr = ptr -> next;
    }

    prePtr -> next = ptr -> next;

    free(ptr);

    return head;
}

struct node *sortList(struct node *head) {

    struct node *ptr1 = head, *ptr2;

    int temp;

    while (ptr1 -> next != head) {
        ptr2 = ptr1 -> next;

        while (ptr2 != head) {

            if (ptr1 -> data > ptr2 -> data) {
                temp = ptr1 -> data;
                ptr1 -> data = ptr2 -> data;
                ptr2 -> data = temp;
            }

            ptr2 = ptr2 -> next;
        }

        ptr1 = ptr1 -> next;
    }

    return head;
}