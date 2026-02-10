/*
An array is divided into two stacks: stack0 and stack1. Stack0 starts from index 0 and grows from left to right.
Stack1 starts at maxsize-1 and grows from right to left. Write the user defined functions for: 
    - Inserting an element into ith stack 
    - Deleting an element from ith stack 
    - Display the content of ith stack
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int arr[MAX];
int top0 = -1;        // Stack0 top
int top1 = MAX;       // Stack1 top

/* ---------------- PUSH into stack i ---------------- */
void push(int i, int value) {
    if (top0 + 1 == top1) {
        printf("Overflow! No space to insert.\n");
        return;
    }

    if (i == 0) {
        arr[++top0] = value;
        printf("Pushed %d into Stack0\n", value);
    }
    else if (i == 1) {
        arr[--top1] = value;
        printf("Pushed %d into Stack1\n", value);
    }
    else {
        printf("Invalid stack number! Use 0 or 1.\n");
    }
}

/* ---------------- POP from stack i ---------------- */
int pop(int i) {
    if (i == 0) {
        if (top0 == -1) {
            printf("Stack0 Underflow!\n");
            return -1;
        }
        return arr[top0--];
    }
    else if (i == 1) {
        if (top1 == MAX) {
            printf("Stack1 Underflow!\n");
            return -1;
        }
        return arr[top1++];
    }
    else {
        printf("Invalid stack number!\n");
        return -1;
    }
}

/* ---------------- DISPLAY stack i ---------------- */
void display(int i) {
    if (i == 0) {
        if (top0 == -1) {
            printf("Stack0 is empty.\n");
            return;
        }
        printf("Stack0 contents: ");
        for (int j = 0; j <= top0; j++)
            printf("%d ", arr[j]);
        printf("\n");
    }
    else if (i == 1) {
        if (top1 == MAX) {
            printf("Stack1 is empty.\n");
            return;
        }
        printf("Stack1 contents: ");
        for (int j = MAX - 1; j >= top1; j--)
            printf("%d ", arr[j]);
        printf("\n");
    }
    else {
        printf("Invalid stack number!\n");
    }
}

/* ---------------- MAIN for testing ---------------- */
int main() {
    push(0, 10);
    push(0, 20);
    push(0, 30);

    push(1, 100);
    push(1, 200);
    push(1, 300);

    display(0);
    display(1);

    printf("Popped from Stack0: %d\n", pop(0));
    printf("Popped from Stack1: %d\n", pop(1));

    display(0);
    display(1);

    return 0;
}
