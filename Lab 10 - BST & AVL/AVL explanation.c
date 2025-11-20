#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    Node* left;
    Node* right;
    int height;
} Node;

// Utility to get height of a node
int height(Node* n) { return n ? n->height : 0; }

// Utility to get max of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// Allocate a new node
Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;   // New node is initially at leaf height = 1
    return node;
}

// Right rotation (LL rotation)
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Left rotation (RR rotation)
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Balance factor of a node
int getBalance(Node* N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}


Node* insertAVL(Node* node, int val) {

    // 1. Normal BST insert
    if (node == NULL)
        return newNode(val);

    if (val < node->val)
        node->left = insertAVL(node->left, val);
    else if (val > node->val)
        node->right = insertAVL(node->right, val);
    else
        return node; // Duplicate vals not allowed

    // 2. Update height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // 3. Get balance factor
    int balance = getBalance(node);

    // 4. Check for 4 imbalance cases:

    // Case 1: LL (Left Left)
    if (balance > 1 && val < node->left->val)
        return rightRotate(node); //LL rotation

    // Case 2: RR (Right Right)
    if (balance < -1 && val > node->right->val)
        return leftRotate(node); //RR rotation

    // Case 3: LR (Left Right)
    if (balance > 1 && val > node->left->val) {
        node->left = leftRotate(node->left); //RR rotation
        return rightRotate(node); //LL rotation
    }

    // Case 4: RL (Right Left)
    if (balance < -1 && val < node->right->val) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // No rotation needed
    return node;
}

// Preorder traversal for checking
void preorder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->val);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    Node* root = NULL;

    int arr[] = {39, 27, 18, 9, 10, 21, 19};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        root = insertAVL(root, arr[i]);
    }

    printf("Preorder traversal of constructed AVL tree:\n");
    preorder(root);
    return 0;
}
