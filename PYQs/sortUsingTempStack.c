#include <stdio.h>

#define MAX 50

int stack0[MAX], stack1[MAX];
int top0 = -1, top1 = -1;

/* ---------- PUSH WITH FLAG ---------- */
void push(int x, int id) {
    if (id == 0)   
        stack0[++top0] = x;
    else           
        stack1[++top1] = x;
}

/* ---------- POP WITH FLAG ---------- */
int pop(int id) {
    if (id == 0)
        return stack0[top0--];
    else
        return stack1[top1--];
}

/* ---------- PEEK ---------- */
int peek(int id) {
    if (id == 0) return stack0[top0];
    else return stack1[top1];
}

/* ---------- CHECK EMPTY ---------- */
int isEmpty(int id) {
    if (id == 0) return top0 == -1;
    else return top1 == -1;
}

/* ---------- SORT STACK USING TEMP STACK ---------- */
void sortStack() {
    while (!isEmpty(0)) {
        int x = pop(0); // top element from main stack

        while (!isEmpty(1) && peek(1) > x) { // compare with temp stack
            push(pop(1), 0);
        }

        push(x, 1);
    }

    while (!isEmpty(1)) {
        push(pop(1), 0);
    }
}

/* ---------- DISPLAY ---------- */
void display() {
    if (isEmpty(0)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack (top to bottom): ");
    for (int i = top0; i >= 0; i--)
        printf("%d ", stack0[i]);
    printf("\n");
}

/* ---------- MAIN ---------- */
int main() {
    int n, val;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        push(val, 0);     // push into main stack
    }

    printf("\nOriginal Stack:\n");
    display();

    sortStack();

    printf("\nSorted Stack (ascending):\n");
    display();

    return 0;
}
