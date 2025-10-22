#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }

int main() {
    char str[MAX], rev[MAX];
    printf("Enter a string: ");
    scanf("%s", str);
    int n = strlen(str);

    // Push all chars
    for (int i = 0; i < n; i++) push(str[i]);
    // Pop to reverse
    for (int i = 0; i < n; i++) rev[i] = pop();
    rev[n] = '\0';

    if (strcmp(str, rev) == 0) printf("Palindrome\n");
    else printf("Not a palindrome\n");
    return 0;
}