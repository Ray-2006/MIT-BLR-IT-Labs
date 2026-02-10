#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
int isEmpty() { return top == -1; }

int main()
{
    char expr[MAX];
    printf("Enter expression: ");
    scanf("%s", expr);

    for (int i = 0; i < strlen(expr); i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[')
            push(expr[i]);
        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            if (isEmpty()) {
                printf("Unbalanced\n");
                return 0;
            }
            char o = pop();
            if ((expr[i] == ')' && o != '(') || (expr[i] == '}' && o != '{') || (expr[i] == ']' && o != '[')) {
                printf("Unbalanced\n");
                return 0;
            }
        }
    }
    if (isEmpty())
        printf("Balanced\n");
    else
        printf("Unbalanced\n");
    return 0;
}
