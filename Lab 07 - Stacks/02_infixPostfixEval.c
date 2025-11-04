#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// ---------- CHAR STACK ----------
typedef struct CharNode {
    char data;
    struct CharNode *next;
} CharNode;

void pushChar(CharNode **top, char c) {
    CharNode *temp = (CharNode *)malloc(sizeof(CharNode));
    if (!temp) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->data = c;
    temp->next = *top;
    *top = temp;
}

char popChar(CharNode **top) {
    if (!*top) {
        return '\0';
    }
    CharNode *temp = *top;
    char c = temp->data;
    *top = temp->next;
    free(temp);
    return c;
}

char peekChar(CharNode *top) {
    return (top ? top->data : '\0');
}

int precedence(char c) {
    switch (c) {
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}

// ---------- INT STACK ----------
typedef struct IntNode {
    int data;
    struct IntNode *next;
} IntNode;

void pushInt(IntNode **top, int val) {
    IntNode *temp = (IntNode *)malloc(sizeof(IntNode));
    if (!temp) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->data = val;
    temp->next = *top;
    *top = temp;
}

int popInt(IntNode **top) {
    if (!*top) {
        printf("Stack underflow\n");
        exit(1);
    }
    IntNode *temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

// ---------- i. Infix to Postfix ----------
void infixToPostfix(char *infix, char *postfix) {
    CharNode *stack = NULL;
    int k = 0;

    for (int i = 0; infix[i]; i++) {
        char c = infix[i];

        if (isdigit(c)) {
            while (isdigit(infix[i])) {
                postfix[k++] = infix[i++];
            }
            postfix[k++] = ' ';
            i--;
        }
        else if (c == '(') {
            pushChar(&stack, c);
        }
        else if (c == ')') {
            while (stack && peekChar(stack) != '(') {
                postfix[k++] = popChar(&stack);
                postfix[k++] = ' ';
            }
            popChar(&stack);
        }
        else if (strchr("+-*/^", c)) {
            while (stack && precedence(peekChar(stack)) >= precedence(c)) {
                postfix[k++] = popChar(&stack);
                postfix[k++] = ' ';
            }
            pushChar(&stack, c);
        }
    }

    while (stack) {
        postfix[k++] = popChar(&stack);
        postfix[k++] = ' ';
    }

    postfix[k] = '\0';
}

// ---------- ii. Evaluate Postfix ----------
int evaluatePostfix(char *expression) {
    IntNode *stack = NULL;

    for (int i = 0; expression[i]; i++) {
        if (expression[i] == ' ')
            continue;

        if (isdigit(expression[i])) {
            int num = 0;
            while (isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--;
            pushInt(&stack, num);
        }
        else if (strchr("+-*/^", expression[i])) {
            int operand2 = popInt(&stack);
            int operand1 = popInt(&stack);

            switch (expression[i]) {
                case '+': pushInt(&stack, operand1 + operand2); break;
                case '-': pushInt(&stack, operand1 - operand2); break;
                case '*': pushInt(&stack, operand1 * operand2); break;
                case '/':
                    if (operand2 == 0) {
                        printf("Division by zero error\n");
                        exit(1);
                    }
                    pushInt(&stack, operand1 / operand2);
                    break;
                case '^': {
                    int res = 1;
                    for (int j = 0; j < operand2; j++)
                        res *= operand1;
                    pushInt(&stack, res);
                    break;
                }
            }
        }
    }
    return popInt(&stack);
}

// ---------- MAIN ----------
int main() {
    char infix[100], postfix[200];
    printf("Enter infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    printf("Result: %d\n", evaluatePostfix(postfix));

    return 0;
}
