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
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void inorderIterative(Node* root) {
    if (root == NULL) return;

    Node* stack[100];
    int top = -1;
    Node* current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

void preorderIterative(Node* root) {
    if (root == NULL) return;

    Node* stack[100];
    int top = -1;
    stack[++top] = root;

    while (top != -1) {
        Node* current = stack[top--];
        printf("%d ", current->data);

        if (current->right) stack[++top] = current->right;
        if (current->left) stack[++top] = current->left;
    }
}

void postorderIterative(Node* root) {
    if (root == NULL) return;

    Node* stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;
    stack1[++top1] = root;

    while (top1 != -1) {
        Node* current = stack1[top1--];
        stack2[++top2] = current;

        if (current->left) stack1[++top1] = current->left;
        if (current->right) stack1[++top1] = current->right;
    }

    while (top2 != -1) {
        printf("%d ", stack2[top2--]->data);
    }
}

Node* findParent(Node* root, int target) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) return NULL;

    if ((root->left && root->left->data == target) || (root->right && root->right->data == target)) {
        return root;
    }

    Node* leftSearch = findParent(root->left, target);
    if (leftSearch) return leftSearch;

    return findParent(root->right, target);
}

int height(Node* root) {
    if (root == NULL) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int printAncestors(Node* root, int target) {
    if (root == NULL) return 0;
    if (root->data == target) return 1;

    if (printAncestors(root->left, target) || printAncestors(root->right, target)) {
        printf("%d ", root->data);
        return 1;
    }
    return 0;
}

int countLeafNodes(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Inorder Traversal: ");
    inorderIterative(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorderIterative(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderIterative(root);
    printf("\n");

    int target = 5;
    Node* parent = findParent(root, target);
    if (parent) {
        printf("Parent of %d: %d\n", target, parent->data);
    } else {
        printf("Parent of %d not found or it is the root node.\n", target);
    }

    printf("Height of tree: %d\n", height(root));

    printf("Ancestors of %d: ", target);
    if (!printAncestors(root, target)) {
        printf("No ancestors found or node does not exist.\n");
    }
    printf("\n");

    printf("Number of leaf nodes: %d\n", countLeafNodes(root));

    return 0;
}

