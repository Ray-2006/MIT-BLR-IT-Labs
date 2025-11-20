#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int priority;
    struct Node *next;
    struct Node *prev;
} Node;

Node *tail = NULL;   // global tail pointer

/* -------------------- ENQUEUE -------------------- */
void enqueue(int data, int priority) {
    Node *newnode = malloc(sizeof(Node));
    newnode->data = data;
    newnode->priority = priority;

    if (tail == NULL) {
        newnode->next = newnode->prev = newnode;
        tail = newnode;
        return;
    }

    Node *head = tail->next;

    newnode->next = head;
    newnode->prev = tail;

    tail->next = newnode;
    head->prev = newnode;

    tail = newnode;   // new node becomes tail
}

/* -------------------- DEQUEUE (MIN PRIORITY) -------------------- */
Node* dequeue() {
    if (tail == NULL) return NULL;  // empty

    Node *head = tail->next;
    Node *current = head;
    Node *minnode = head;

    /* find minimum priority node */
    do {
        if (current->priority < minnode->priority)
            minnode = current;
        current = current->next;
    } while (current != head);

    /* if only one node */
    if (minnode->next == minnode) {
        tail = NULL;
        return minnode;   // caller will free if needed
    }

    /* unlink */
    minnode->prev->next = minnode->next;
    minnode->next->prev = minnode->prev;

    /* if we removed tail, update tail */
    if (minnode == tail)
        tail = minnode->prev;

    return minnode;
}

/* -------------------- DEBUG PRINT -------------------- */
void printQueue() {
    if (tail == NULL) {
        printf("(empty)\n");
        return;
    }
    Node *head = tail->next;
    Node *current = head;

    printf("Queue: ");
    do {
        printf("(%d,p=%d) ", current->data, current->priority);
        current = current->next;
    } while (current != head);

    printf("\n");
}

/* -------------------- MAIN EXAMPLE -------------------- */
int main() {
    enqueue(10,5);
    enqueue(20,3);
    enqueue(30,9);
    enqueue(40,1);

    printf("Initial queue (head to tail):\n");
    printQueue();

    Node *r = dequeue();
    printf("Dequeued: %d (p=%d)\n", r->data, r->priority);
    free(r);

    printQueue();
}