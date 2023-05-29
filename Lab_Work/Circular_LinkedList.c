// Circular linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        newNode->next = head->next;
        head->next = newNode;
    }
    return head;
}

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        newNode->next = head->next;
        head->next = newNode;
        head = newNode;
    }
    return head;
}

void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* current = head->next;
    printf("Circular Linked List: ");
    while (current != head) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("%d", current->data);
    printf("\n");
}

int main() {
    Node* head = NULL;

    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);

    displayList(head);

    return 0;
}
