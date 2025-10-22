#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int c, e;
    struct Node *prev, *next;
} Node;

Node *newNode(int c, int e)
{
    Node *t = (Node *)malloc(sizeof(Node));
    t->c = c;
    t->e = e;
    t->prev = t->next = NULL;
    return t;
}

void insert(Node **h, int c, int e)
{
    if (c == 0)
        return;
    Node *n = newNode(c, e), *t = *h, *p = NULL;
    while (t && t->e > e)
    {
        p = t;
        t = t->next;
    }
    if (t && t->e == e)
    {
        t->c += c;
        free(n);
        return;
    }
    if (!p)
    {
        n->next = *h;
        if (*h)
            (*h)->prev = n;
        *h = n;
    }
    else
    {
        n->next = t;
        n->prev = p;
        p->next = n;
        if (t)
            t->prev = n;
    }
}

void show(Node *h)
{
    while (h)
    {
        printf("%dx^%d", h->c, h->e);
        if (h->next)
            printf(" + ");
        h = h->next;
    }
}

Node *add(Node *a, Node *b)
{
    Node *r = NULL;
    while (a)
    {
        insert(&r, a->c, a->e);
        a = a->next;
    }
    while (b)
    {
        insert(&r, b->c, b->e);
        b = b->next;
    }
    return r;
}

Node *input()
{
    int n, c, e;
    Node *p = NULL;
    printf("No. of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &c, &e);
        insert(&p, c, e);
    }
    return p;
}

int main()
{
    Node *p1 = input(), *p2 = input(), *s = add(p1, p2);
    printf("P1: ");
    show(p1);
    printf("\nP2: ");
    show(p2);
    printf("\nSum: ");
    show(s);
}
