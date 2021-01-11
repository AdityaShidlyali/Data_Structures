// Author : Aditya Shidlyali

// Program to implement the operations on doubly linked list

#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct node *getNode(int item) {
    struct node *newNode = (struct node *) malloc(sizeof(struct node *));

    newNode -> prev = NULL;
    newNode -> data = item;
    newNode -> next = NULL;

    return newNode;
}

struct node *createLinkedList(struct node *);
struct node *displayLinkedList(struct node *);
struct node *insertBeginning(struct node *);
struct node *insertEnd(struct node *);
struct node *insertBefore(struct node *);
struct node *insertAfter(struct node *);
struct node *deleteBeginning(struct node *);
struct node *deleteEnd(struct node *);
struct node *deleteNode(struct node *);
struct node *deleteAfter(struct node *);
struct node *deleteEntireList(struct node *);
struct node *sortList(struct node *);

int main() {

    struct node *head = NULL;

    int option;
    do {

        printf("\n\n---Linked List operations---\n");
        printf("1. Create a linked list\n");
        printf("2. Display linked list\n");
        printf("3. Add a node at the beginning\n");
        printf("4. Add a node at the end\n");
        printf("5. Add a node before a given node\n");
        printf("6. Add a node after a given node\n");
        printf("7. Delete a node from the beginning\n");
        printf("8. Delete a node from the end\n");
        printf("9. Delete a given node\n");
        printf("10. Delete a node after a given node\n");
        printf("11. Delete the entire list\n");
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
            case 5: head = insertBefore(head);
            break;
            case 6: head = insertAfter(head);
            break;
            case 7: head = deleteBeginning(head);
            break;
            case 8: head = deleteEnd(head);
            break;
            case 9: head = deleteNode(head);
            break;
            case 10: head = deleteAfter(head);
            break;
            case 11: head = deleteEntireList(head);
            break;
            case 12: head = sortList(head);
            break;

            case 13: exit(0);
            break;

            default: printf("Enter valid option !!");
            break;
        }

    } while (1);

    return 0;
}

struct node *createLinkedList(struct node *head) {

    struct node *ptr = head, *newNode;

    int item;
    printf("Enter -1 to exit inserting the data\n");
    printf("Enter data to be inserted : \n");
    scanf("%d", &item);

    while (item != -1) {

        newNode = getNode(item);

        if (head == NULL) {
            head = newNode;
        } else {

            ptr = head;

            while (ptr -> next != NULL) {
                ptr = ptr -> next;
            }

            ptr -> next = newNode;
            newNode -> next = NULL;
            newNode -> prev = ptr;
        }

        printf("Enter -1 to exit inserting the data\n");
        printf("Enter data to be inserted : \n");
        scanf("%d", &item);
    }

    return head;
}

struct node *displayLinkedList(struct node *head) {

    struct node *ptr = head;

    while (ptr != NULL) {
        printf(" <= %d => ", ptr -> data);
        ptr = ptr -> next;
    }

    return head;
}

struct node *insertBeginning(struct node *head) {

    struct node *ptr;
    int item;
    printf("Enter the data to insert into the node : ");
    scanf("%d", &item);

    struct node *newNode = getNode(item);

    head -> prev = newNode;
    newNode -> prev = NULL;
    newNode -> next = head;

    head = newNode;

    return head;
}

struct node *insertEnd(struct node *head) {

    struct node *ptr = head;

    int item;
    printf("Enter item to insert to the node : ");
    scanf("%d", &item);

    struct node *newNode = getNode(item);

    while (ptr -> next != NULL) {
        ptr = ptr -> next;
    }

    ptr -> next = newNode;
    newNode -> prev = ptr;
    newNode -> next = NULL;

    return head;
}

struct node *insertBefore (struct node *head) {

    struct node *ptr = head;

    int key;
    printf("Enter the node value for reference, to insert before : ");
    scanf("%d", &key);

    int item;
    printf("Enter the data to be inserted for the new node : ");
    scanf("%d", &item);

    struct node *newNode = getNode(item);

    while (ptr -> data != key) {
        ptr = ptr -> next;
    }

    newNode -> prev = ptr -> prev;
    newNode -> next = ptr;

    ptr -> prev -> next = newNode;
    ptr -> prev = newNode;

    return head;
}

struct node *insertAfter(struct node *head) {

    int key;
    printf("Enter the data of node for reference, to insert after : ");
    scanf("%d", &key);

    int item;
    printf("Enter the data for the new node : ");
    scanf("%d", &item);

    struct node *ptr = head, *newNode = getNode(item);

    while (ptr -> data != key) {
        ptr = ptr -> next;
    }

    newNode -> prev = ptr;
    ptr -> next -> prev = newNode;
    newNode -> next = ptr -> next;
    ptr -> next = newNode;

    return head;
}

struct node *deleteBeginning(struct node *head) {

    struct node *ptr = head;

    head = head -> next;
    head -> prev = NULL;

    free(ptr);

    return head;
}

struct node *deleteEnd(struct node *head) {

    struct node *ptr = head;
    while (ptr -> next != NULL) {
        ptr = ptr -> next;
    }

    ptr -> prev -> next = NULL;

    free(ptr);

    return head;
}

struct node *deleteNode(struct node *head) {

    int key;
    printf("Enter the data of the node to be deleted : ");
    scanf("%d", &key);

    struct node *ptr = head;

    while (ptr -> data != key) {
        ptr = ptr -> next;
    }

    ptr -> prev -> next = ptr -> next;
    ptr -> next -> prev = ptr -> prev;

    free(ptr);

    return head;
}

struct node *deleteAfter(struct node *head) {

    struct node *ptr = head;

    int key;
    printf("Enter the value of the node for the reference, to delete after : ");
    scanf("%d", &key);

    while (ptr -> data != key) {
        ptr = ptr -> next;
    }

    struct node *temp = ptr -> next;

    ptr -> next = temp -> next;
    temp -> next -> prev = ptr;

    free(temp);

    return head;
}

struct node *deleteEntireList(struct node *head) {

    while (head -> next != NULL) {
        head = deleteBeginning(head);
    }

    free(head);

    return NULL;
}

struct node *sortList(struct node *head) {

    struct node *ptr1 = head, *ptr2;

    while (ptr1 -> next != NULL) {
        ptr2 = ptr1 -> next;

        while (ptr2 != NULL) {

            if (ptr1 -> data > ptr2 -> data) {
                int temp = ptr1 -> data;
                ptr1 -> data = ptr2 -> data;
                ptr2 -> data = temp;
            }

            ptr2 = ptr2 -> next;
        }

        ptr1 = ptr1 -> next;
    }

    return head;
}