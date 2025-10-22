#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int coef;
    int exp;
    struct Node *prev, *next;
} Node;

// Function to create a new node
Node *createNode(int coef, int exp)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Insert node in descending order of exponents
void insertTerm(Node **head, int coef, int exp)
{
    if (coef == 0)
        return; // Ignore 0 coefficients̥
    Node *newNode = createNode(coef, exp);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    Node *prev = NULL;

    // Insert in descending order
    while (temp != NULL && temp->exp > exp)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL && temp->exp == exp)
    {
        // If exponent exists, update coefficient
        temp->coef += coef;
        free(newNode);
        if (temp->coef == 0)
        { // Remove if coef becomes 0
            if (temp->prev)
                temp->prev->next = temp->next;
            if (temp->next)
                temp->next->prev = temp->prev;
            if (temp == *head)
                *head = temp->next;
            free(temp);
        }
        return;
    }

    if (prev == NULL)
    {
        // Insert at head
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
    else
    {
        // Insert in between or at end
        newNode->next = temp;
        newNode->prev = prev;
        prev->next = newNode;
        if (temp)
            temp->prev = newNode;
    }
}

// Function to display polynomial
void display(Node *head)
{
    if (!head)
    {
        printf("0");
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%dx^%d", temp->coef, temp->exp);
        if (temp->next != NULL && temp->next->coef > 0)
            printf(" + ");
        else if (temp->next != NULL && temp->next->coef < 0)
            printf(" ");
        temp = temp->next;
    }
}

// Function to add two polynomials
Node *addPolynomials(Node *p1, Node *p2)
{
    Node *result = NULL;
    Node *t1 = p1;
    Node *t2 = p2;

    while (t1 != NULL)
    {
        insertTerm(&result, t1->coef, t1->exp);
        t1 = t1->next;
    }
    while (t2 != NULL)
    {
        insertTerm(&result, t2->coef, t2->exp);
        t2 = t2->next;
    }

    return result;
}

// Function to take input for a polynomial
Node *inputPolynomial()
{
    Node *poly = NULL;
    int n, coef, exp;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coef, &exp);
        insertTerm(&poly, coef, exp);
    }
    return poly;
}

int main()
{
    Node *poly1 = NULL, *poly2 = NULL, *sum = NULL;

    printf("Enter first polynomial:\n");
    poly1 = inputPolynomial();

    printf("\nEnter second polynomial:\n");
    poly2 = inputPolynomial();

    sum = addPolynomials(poly1, poly2);

    printf("\nFirst Polynomial: ");
    display(poly1);
    printf("\nSecond Polynomial: ");
    display(poly2);
    printf("\nSum Polynomial: ");
    display(sum);

    return 0;
}
