/*Write a recursive function to:
i) Create a binary tree ii) printTree the binary tree (in traversal order, typically level-order)
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *createNode(int data) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

Node *createBinaryTree() {
    int data;
    printf("Enter node data (-1 for NULL): ");
    scanf("%d", &data);
    if (data == -1) return NULL;

    Node *n = createNode(data);
    printf("Enter left child of %d:\n", data);
    n->left = createBinaryTree();
    printf("Enter right child of %d:\n", data);
    n->right = createBinaryTree();
    return n;
}

int treeHeight(Node *root) {
    if (!root) return 0;
    int lh = treeHeight(root->left), rh = treeHeight(root->right);
    return (lh > rh ? lh : rh) + 1;
}

void printLevel(Node *root, int level) {
    if (!root) return;
    if (level == 1) printf("%d ", root->data);
    else {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

void printTree(Node *root) {
    int h = treeHeight(root);
    for (int i = 1; i <= h; i++)
        printLevel(root, i);
}

/*
void printTreeVisual(Node *root, int space)
{
    if (!root)
        return;

    // increase distance between levels
    space += 6;

    // print right subtree first
    printTreeVisual(root->right, space);

    // print current node after spaces
    printf("\n");
    for (int i = 6; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    // print left subtree
    printTreeVisual(root->left, space);
}*/
int main()
{
    Node *root = createBinaryTree();
    printf("Level order traversal of the binary tree:\n");

    printTree(root);
    printf("\n");
    return 0;
}
