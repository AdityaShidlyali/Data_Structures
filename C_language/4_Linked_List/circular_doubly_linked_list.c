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
            newNode -> next = head;
        } else {

            ptr = head;

            while (ptr -> next != head) {
                ptr = ptr -> next;
            }

            newNode -> prev = ptr;
            ptr -> next = newNode;
            newNode -> next = head;
            head -> prev = newNode;
        }

        printf("Enter -1 to exit inserting the data\n");
        printf("Enter data to be inserted : \n");
        scanf("%d", &item);
    }

    return head;
}

struct node *displayLinkedList(struct node *head) {

    struct node *ptr = head;

    while (ptr -> next != head) {
        printf(" %d ", ptr -> data);
        ptr = ptr -> next;
    }

    printf(" %d", ptr -> data);

    return head;
}

struct node *insertBeginning(struct node *head) {

    struct node *ptr;
    int item;
    printf("Enter the data to insert into the node : ");
    scanf("%d", &item);

    struct node *newNode = getNode(item);

    head -> prev -> next = newNode;
    newNode -> next = head;
    newNode -> prev = head -> prev;
    head -> prev = newNode;
    head = newNode;

    return head;
}

struct node *insertEnd(struct node *head) {

    struct node *ptr = head;

    int item;
    printf("Enter item to insert to the node : ");
    scanf("%d", &item);

    struct node *newNode = getNode(item);

    head -> prev -> next = newNode;
    newNode -> prev = head -> prev;
    head -> prev = newNode;
    newNode -> next = head;

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

    ptr -> prev -> next = newNode;
    newNode -> prev = ptr -> prev;
    newNode -> next = ptr;
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

    ptr -> next -> prev = newNode;
    newNode -> next = ptr -> next;
    newNode -> prev = ptr;
    ptr -> next = newNode;

    return head;
}

struct node *deleteBeginning(struct node *head) {

    struct node *ptr = head;

    head -> next -> prev = head -> prev;
    head -> prev -> next = head -> next;
    head = head -> next;

    free(ptr);

    return head;
}

struct node *deleteEnd(struct node *head) {

    struct node *ptr = head -> prev;

    ptr -> prev -> next = head;
    head -> prev = ptr -> prev;

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
    struct node *prePtr;

    int key;
    printf("Enter the value of the node for the reference, to delete after : ");
    scanf("%d", &key);

    while (ptr -> data != key) {
        prePtr = ptr;
        ptr = ptr -> next;
    }
    
    prePtr = ptr;
    ptr = ptr -> next;
    prePtr -> next = ptr -> next;
    ptr -> next -> prev = prePtr;

    free(ptr);

    return head;
}

struct node *deleteEntireList(struct node *head) {

    struct node *ptr = head;

    while (ptr -> next != head) {
        head = deleteEnd(head);
    }

    free(head);

    return head;
}

struct node *sortList(struct node *head) {

    struct node *ptr1 = head, *ptr2;

    while (ptr1 -> next != head) {
        ptr2 = ptr1 -> next;

        while (ptr2 != head) {

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