/*
1.
Write user-defined functions to perform the following operations on binary trees:
i) Inorder traversal (Iterative) 
ii) Postorder traversal (Iterative) 
iii) Preorder traversal (Iterative) 
iv) Print the parent of a given element 
v) Print the depth (or height) of the tree 
vi) Print the ancestors of a given element 
vii) Count the number of leaf nodes in a binary tree
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

void inorder(Node* r) {
    if (!r) return;
    Node* stack[100]; int top = -1;
    while (r || top != -1) {
        while (r) { stack[++top] = r; r = r->left; }
        r = stack[top--];
        printf("%d ", r->data);
        r = r->right;
    }
}

void preorder(Node* r) {
    if (!r) return;
    Node* stack[100]; int top = -1;
    stack[++top] = r;
    while (top != -1) {
        r = stack[top--];
        printf("%d ", r->data);
        if (r->right) stack[++top] = r->right;
        if (r->left) stack[++top] = r->left;
    }
}

void postorder(Node* r) {
    if (!r) return;
    Node *s1[100], *s2[100];
    int t1 = -1, t2 = -1;
    s1[++t1] = r;
    while (t1 != -1) {
        r = s1[t1--];
        s2[++t2] = r;
        if (r->left) s1[++t1] = r->left;
        if (r->right) s1[++t1] = r->right;
    }
    while (t2 != -1) printf("%d ", s2[t2--]->data);
}

Node* findParent(Node* r, int x) {
    if (!r || (!r->left && !r->right)) return NULL;
    if ((r->left && r->left->data == x) || (r->right && r->right->data == x)) return r;
    Node* p = findParent(r->left, x);
    return p ? p : findParent(r->right, x);
}

int height(Node* r) {
    if (!r) return 0;
    int lh = height(r->left), rh = height(r->right);
    return (lh > rh ? lh : rh) + 1;
}

int printAnc(Node* r, int x) {
    if (!r) return 0;
    if (r->data == x) return 1;
    if (printAnc(r->left, x) || printAnc(r->right, x)) {
        printf("%d ", r->data);
        return 1;
    }
    return 0;
}

int countLeaf(Node* r) {
    if (!r) return 0;
    if (!r->left && !r->right) return 1;
    return countLeaf(r->left) + countLeaf(r->right);
}

int main() {
    Node* r = createNode(1);
    r->left = createNode(2);
    r->right = createNode(3);
    r->left->left = createNode(4);
    r->left->right = createNode(5);
    r->right->left = createNode(6);
    r->right->right = createNode(7);

    printf("Inorder: "); inorder(r);
    printf("\nPreorder: "); preorder(r);
    printf("\nPostorder: "); postorder(r);

    int x = 5;
    Node* p = findParent(r, x);
    if (p) printf("\nParent of %d: %d", x, p->data);
    else printf("\nParent of %d not found or it is root.", x);

    printf("\nHeight: %d", height(r));
    printf("\nAncestors of %d: ", x);
    if (!printAnc(r, x)) printf("None");
    printf("\nLeaf nodes: %d\n", countLeaf(r));

    return 0;
}


