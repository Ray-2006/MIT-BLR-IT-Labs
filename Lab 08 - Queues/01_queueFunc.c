#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

typedef struct {
    int id;
    char name[30];
} Job;

typedef struct {
    Job jobs[MAX];
    int front, rear;
} Queue;

void init(Queue *q) { q->front = q->rear = -1; }
int isFull(Queue *q) { return q->rear == MAX - 1; }
int isEmpty(Queue *q) { return q->front == -1; }

void enqueue(Queue *q, Job job) {
    if (isFull(q)) {
        printf("\nQueue Full! Cannot add job %d.\n", job.id);
        return;
    }
    if (isEmpty(q))
        q->front = 0;
    q->rear++;
    q->jobs[q->rear] = job;
    printf("\nJob Enqueued: ID: %d, Name: %s\n", job.id, job.name);
}

void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("\nQueue Empty!\n");
        return;
    }
    Job job = q->jobs[q->front];
    printf("\nPrinting Job: ID: %d, Name: %s\n", job.id, job.name);
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("\nQueue Empty!\n");
        return;
    }
    printf("\nCurrent queue:\n");
    printf("ID\tName\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d\t%s\n", q->jobs[i].id, q->jobs[i].name);
    }
}

int main() {
    Queue q;
    init(&q);

    int choice;
    do {
        printf("\n1. Add Random Job\n2. Print Next Job\n3. Display queue\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            Job job;
            job.id = rand() % 1000;
            sprintf(job.name, "Doc_%d", job.id);
            enqueue(&q, job);
        } else if (choice == 2) {
            dequeue(&q);
        } else if (choice == 3) {
            display(&q);
        } 
    } while (choice != 4);

    return 0;
}
