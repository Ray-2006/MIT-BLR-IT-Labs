#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// ---------- CHAR STACK ----------
struct CharNode {
    char data;
    struct CharNode* next;
};

void pushChar(struct CharNode** top, char c) {
    struct CharNode* temp = (struct CharNode*)malloc(sizeof(struct CharNode));
    temp->data = c; temp->next = *top; *top = temp;
}
char popChar(struct CharNode** top) {
    if (!*top) return '\0';
    struct CharNode* temp = *top;
    char c = temp->data;
    *top = temp->next;
    free(temp);
    return c;
}
char peekChar(struct CharNode* top) { return top ? top->data : '\0'; }
int precedence(char c) {
    if(c=='^') return 3;
    if(c=='*'||c=='/') return 2;
    if(c=='+'||c=='-') return 1;
    return 0;
}

// ---------- INT STACK ----------
struct IntNode {
    int data;
    struct IntNode* next;
};

void pushInt(struct IntNode** top, int val) {
    struct IntNode* temp = (struct IntNode*)malloc(sizeof(struct IntNode));
    temp->data = val; temp->next = *top; *top = temp;
}
int popInt(struct IntNode** top) {
    if (!*top) {
        printf("Stack underflow\n");
        exit(1);
    }
    struct IntNode* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

// ---------- i. Infix to Postfix (with spaces) ----------
void infixToPostfix(char* infix, char* postfix) {
    struct CharNode* stack = NULL;
    int k = 0;
    for (int i = 0; infix[i]; i++) {
        char c = infix[i];
        if (isdigit(c)) {
            // collect full number
            while (isdigit(infix[i])) {
                postfix[k++] = infix[i++];
            }
            postfix[k++] = ' '; // delimiter
            i--; // step back
        }
        else if (c=='(') pushChar(&stack, c);
        else if (c==')') {
            while (stack && peekChar(stack)!='(') {
                postfix[k++] = popChar(&stack);
                postfix[k++] = ' ';
            }
            popChar(&stack); // remove '('
        }
        else if (c=='+'||c=='-'||c=='*'||c=='/'||c=='^') {
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

// ---------- ii. Evaluate Postfix (with spaces) ----------
int evaluatePostfix(char *expression) {
    struct IntNode* stack = NULL;

    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == ' ') continue;

        if (isdigit(expression[i])) {
            int num = 0;
            while (isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--; // step back
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
                    pushInt(&stack, operand1 / operand2); break;
                case '^': {
                    int res = 1;
                    for (int j=0; j<operand2; j++) res *= operand1;
                    pushInt(&stack, res);
                    break;
                }
            }
        }
    }
    return popInt(&stack);
}

int main() {
    char infix[100], postfix[200];
    printf("Enter infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = 0;

    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);

    printf("Postfix evaluation: %d\n", evaluatePostfix(postfix));
    return 0;
}
