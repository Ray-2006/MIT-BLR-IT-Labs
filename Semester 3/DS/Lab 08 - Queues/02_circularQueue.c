//circular queue

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int arr[MAX];
    int front, rear;
} Queue;

void init(Queue *q) { q->front = q->rear = -1; }
int isFull(Queue *q) { return (q->rear + 1) % MAX == q->front; }
int isEmpty(Queue *q) { return q->front == -1; }

void enqueue(Queue *q, int val) {
    if (isFull(q)) {
        printf("Queue Full!\n");
        return;
    }
    if (isEmpty(q)){ 
        q->front = 0; 
    }
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = val;
    printf("Inserted: %d\n", val);
}

void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Empty!\n");
        return;
    }
    printf("Deleted: %d\n", q->arr[q->front]);
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front = (q->front + 1) % MAX;
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Empty!\n");
        return;
    }
    int i = q->front;
    printf("Queue: ");
    while (1) {
        printf("%d ", q->arr[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Queue q;
    init(&q);
    int ch, val;

    do {
        printf("\n1. Enqueue random\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: val = rand() % 1000; enqueue(&q, val); break;
            case 2: dequeue(&q); break;
            case 3: display(&q); break;
        }
    } while (ch != 4);

    return 0;
}
