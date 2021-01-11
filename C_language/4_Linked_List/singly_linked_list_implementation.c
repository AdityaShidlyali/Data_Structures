// Author : Aditya Shidlyali

// Program to implement the operations on singly linked list

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
        printf("2. Display the list\n");
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
            default: printf("\nEnter valid option !\n");
            break;
        }

    } while (1);

    return 0;
}

struct node *createLinkedList(struct node *head) {

    struct node *newNode, *ptr;

    int item;
    printf("\nEnter -1 to end inserting");
    printf("\nEnter data to be inserted : ");
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
        }

        printf("\nEnter -1 to end inserting");
        printf("\nEnter data to be inserted : ");
        scanf("%d", &item);
    }

    return head;
}

struct node *displayLinkedList(struct node *head) {

    struct node *ptr;

    ptr = head;

    printf("\nThe Linked List is : \n");
    
    while (ptr != NULL) {

        printf("%d => ", ptr -> data);

        ptr = ptr -> next;
    }

    return head;
}

struct node *insertBeginning(struct node *head) {

    int item;
    printf("\nEnter data to be inserted : ");
    scanf("%d", &item);

    struct node *newNode, *ptr;

    ptr = head;

    newNode = getNode(item);

    newNode -> data = item;

    head = newNode;

    newNode -> next = ptr;
	
    return head;
}

struct node *insertEnd(struct node *head) {

    int item;
    printf("\nEnter data to be inserted : ");
    scanf("%d", &item);

    struct node *newNode, *ptr;
    
    ptr = head;

    newNode = (struct node *) malloc(sizeof(struct node));
    newNode -> data = item;
    newNode -> next = NULL;

    while (ptr -> next != NULL) {
        ptr = ptr -> next;
    }

    ptr -> next = newNode;

    return head;
}

struct node *insertBefore(struct node *head) {

    int item;
    printf("\nEnter data to insert to the node : ");
    scanf("%d", &item);

    int beforeItem;
    printf("Enter the data of the node to be inserted before : ");
    scanf("%d", &beforeItem);

    struct node *newNode, *ptr;

    newNode = (struct node *) malloc(sizeof(struct node));

    newNode -> data = item;

    ptr = head;

    struct node *pre_ptr = ptr;

    while (ptr -> data != beforeItem) {
        pre_ptr = ptr;
        ptr = ptr -> next;
    }

    pre_ptr -> next = newNode;

    newNode -> next = ptr;

    return head;
}

struct node *insertAfter(struct node *head) {

    int item;
    printf("\nEnter data tobe inserted : ");
    scanf("%d", &item);

    struct node *newNode, *ptr;
    newNode = (struct node *) malloc(sizeof(struct node *));
    newNode -> data = item;
    newNode -> next = NULL;

    int afterValue;
    printf("Enter the node value which the node to be inserted : ");
    scanf("%d", &afterValue);

    ptr = head;

    struct node *postNode = ptr;

    while (ptr -> data != afterValue) {
        ptr = ptr -> next;
        postNode = ptr;
    }

    postNode = postNode -> next;

    ptr -> next = newNode;

    newNode -> next = postNode;

    return head;
}

struct node *deleteBeginning (struct node *head) {
	
	struct node *ptr = head;

    head = head -> next;

    free(ptr);

    return head;
	
}

struct node *deleteEnd (struct node *head) {

    struct node *ptr = head;

    struct node *prePtr;

    while (ptr -> next != NULL) {
        prePtr = ptr;
        ptr = ptr -> next;
    }

    prePtr -> next = NULL;

    free(ptr);

    return head;

}

struct node *deleteNode (struct node *head) {

    struct node *ptr = head;
    struct node *prePtr = ptr;

    int key;
    printf("Enter value of the node to be deleted : ");
    scanf("%d", &key);

    if (ptr -> data == key) {
        head = deleteBeginning(head);
    } else {

        while (ptr -> data != key) {
            prePtr = ptr;
            ptr = ptr -> next;
        }

        prePtr -> next = ptr -> next;

        free(ptr);
    }

    return head;
}

struct node *deleteAfter (struct node *head) {

    struct node *ptr = head;

    int key;
    printf("Enter the data of the node with reference to delete after node : ");
    scanf("%d", &key);

    struct node *prePtr = ptr;

    while (prePtr -> data != key) {
        prePtr = ptr;
        ptr = ptr -> next;
    }

    prePtr -> next = ptr -> next;

    free(ptr);

    return head;
}

struct node *deleteEntireList (struct node *head) {

    struct node *ptr;

    if (head != NULL) {
        ptr = head;
        while (ptr -> next != NULL) {
            head = deleteBeginning(ptr);
            ptr = head;
        }
    }

    head = NULL;

    return head;
}

struct node *sortList (struct node *head) {

    struct node *ptr1, *ptr2;

    int temp;

    ptr1 = head;

    while (ptr1 -> next != NULL) {
        ptr2 = ptr1 -> next;

        while (ptr2 != NULL) {

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