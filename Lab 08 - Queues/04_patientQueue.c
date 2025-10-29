#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Patient {
    char name[30];
    int age;
    int priority;
    struct Patient *next;
} Patient;

typedef struct {
    Patient *front, *rear;
} Queue;

void init(Queue *q) {
    q->front = q->rear = NULL;
}

void enqueue(Queue *q, char *name, int age) {
    static int nextPriority = 1;

    Patient *p = malloc(sizeof(Patient));
    strcpy(p->name, name);
    p->age = age;
    p->priority = nextPriority++;
    p->next = NULL;

    if (!q->rear)
        q->front = q->rear = p;
    else {
        q->rear->next = p;
        q->rear = p;
    }

    printf("Added: %s (Age %d, Priority %d)\n", name, age, p->priority);
}

void dequeue(Queue *q) {
    if (!q->front) {
        printf("Queue Empty!\n");
        return;
    }
    Patient *temp = q->front;
    printf("Attending: %s (Priority %d)\n", temp->name, temp->priority);
    q->front = temp->next;
    if (!q->front) q->rear = NULL;
    free(temp);
}

void display(Queue *q) {
    if (!q->front) {
        printf("Queue Empty!\n");
        return;
    }
    printf("\nPatient Queue:\n");
    for (Patient *t = q->front; t; t = t->next)
        printf("Name: %s | Age: %d | Priority: %d\n", t->name, t->age, t->priority);
}

int main() {
    Queue q;
    init(&q);
    int ch, age;
    char name[30];

    do {
        printf("\n1. Add Patient\n2. Attend Patient\n3. Display\n4. Exit\nEnter choice: ");
        /*if (scanf("%d", &ch) != 1) {
            while (getchar() != '\n');
            ch = 0;
        }*/
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter name and age: ");
                scanf("%s%d", name, &age);
                enqueue(&q, name, age);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
        }
    } while (ch != 4);

    return 0;
}
