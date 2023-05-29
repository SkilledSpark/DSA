// Doubly linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    return head;
}

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
    return head;
}

void displayForward(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* current = head;
    printf("Doubly Linked List (Forward): ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void displayReverse(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    printf("Doubly Linked List (Reverse): ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);

    displayForward(head);
    displayReverse(head);

    return 0;
}
