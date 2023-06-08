//reversing a linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} NODE;

NODE* createNode(int data) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(NODE** head, int data) {
    NODE* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        NODE* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void reverseLinkedList(NODE** head) {
    NODE *prevNode = NULL, *currentNode = *head, *nextNode = NULL;
    while (currentNode != NULL) {
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    *head = prevNode;
}

void printLinkedList(NODE* head) {
    NODE* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    NODE* head = NULL;
    int n, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertNode(&head, data);
    }

    printf("Original Linked List: ");
    printLinkedList(head);

    reverseLinkedList(&head);

    printf("Reversed Linked List: ");
    printLinkedList(head);

    return 0;
}
