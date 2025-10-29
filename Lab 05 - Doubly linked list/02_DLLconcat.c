#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void insertRear(Node** head, Node** tail, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

void traverse(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void concatenate(Node** head1, Node** tail1, Node* head2, Node* tail2) {
    if (*head1 == NULL) {
        *head1 = head2;
        *tail1 = tail2;
        return;
    }
    if (head2 == NULL) return;
    (*tail1)->next = head2;
    head2->prev = *tail1;
    *tail1 = tail2;
}

int main() {
    Node *head1 = NULL, *tail1 = NULL;
    Node *head2 = NULL, *tail2 = NULL;

    insertRear(&head1, &tail1, 10);
    insertRear(&head1, &tail1, 20);
    insertRear(&head1, &tail1, 30);

    insertRear(&head2, &tail2, 40);
    insertRear(&head2, &tail2, 50);
    insertRear(&head2, &tail2, 60);

    printf("List 1: "); traverse(head1);
    printf("List 2: "); traverse(head2);

    concatenate(&head1, &tail1, head2, tail2);

    printf("Concatenated List: "); traverse(head1);

    return 0;
}