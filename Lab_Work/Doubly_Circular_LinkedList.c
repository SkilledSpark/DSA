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
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    } else {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
    return head;
}

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    } else {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
    }
    return head;
}

void displayForward(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* current = head;
    printf("Doubly Circular Linked List (Forward): ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

void displayReverse(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* current = head->prev;
    printf("Doubly Circular Linked List (Reverse): ");
    do {
        printf("%d ", current->data);
        current = current->prev;
    } while (current != head->prev);
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
