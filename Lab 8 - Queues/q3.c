// singly linked list queue

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front, *rear;
} Queue;

void init(Queue *q) {
    q->front = q->rear = NULL;
}

void enqueue(Queue *q, int val) {
    Node *temp = malloc(sizeof(Node));
    temp->data = val;
    temp->next = NULL;

    if (q->rear == NULL)
        q->front = q->rear = temp;
    else {
        q->rear->next = temp;
        q->rear = temp;
    }
    printf("Enqueued: %d\n", val);
}

void dequeue(Queue *q) {
    if (q->front == NULL) {
        printf("Queue Empty!\n");
        return;
    }
    Node *temp = q->front;
    printf("Dequeued: %d\n", temp->data);
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
}

void display(Queue *q) {
    Node *temp = q->front;
    printf("Queue: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue q;
    init(&q);
    int ch, val;
    do {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Enter value: "); scanf("%d", &val); enqueue(&q, val); break;
            case 2: dequeue(&q); break;
            case 3: display(&q); break;
        }
    } while (ch != 4);
    return 0;
}
