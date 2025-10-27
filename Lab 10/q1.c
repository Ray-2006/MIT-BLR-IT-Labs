#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data, height;
    struct Node *left, *right;
} Node;

Node *createNode(int d)
{
    Node *n = malloc(sizeof(Node));
    n->data = d;
    n->left = n->right = NULL;
    n->height = 1;
    return n;
}
int height(Node *n) { return n ? n->height : 0; }
int max(int a, int b) { return a > b ? a : b; }
int getBalance(Node *n) { return n ? height(n->left) - height(n->right) : 0; }

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    return x;
}
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}

// ---------- BST Functions ----------
Node *insertBST(Node *root, int d)
{
    if (!root)
        return createNode(d);
    if (d < root->data)
        root->left = insertBST(root->left, d);
    else if (d > root->data)
        root->right = insertBST(root->right, d);
    return root;
}
void inorder(Node *r)
{
    if (r)
    {
        inorder(r->left);
        printf("%d ", r->data);
        inorder(r->right);
    }
}
void preorder(Node *r)
{
    if (r)
    {
        printf("%d ", r->data);
        preorder(r->left);
        preorder(r->right);
    }
}
void postorder(Node *r)
{
    if (r)
    {
        postorder(r->left);
        postorder(r->right);
        printf("%d ", r->data);
    }
}
Node *search(Node *r, int k) { return (!r || r->data == k) ? r : (k < r->data ? search(r->left, k) : search(r->right, k)); }
Node *findMin(Node *r)
{
    while (r && r->left)
        r = r->left;
    return r;
}
Node *findMax(Node *r)
{
    while (r && r->right)
        r = r->right;
    return r;
}

Node *deleteBST(Node *r, int k)
{
    if (!r)
        return r;
    if (k < r->data)
        r->left = deleteBST(r->left, k);
    else if (k > r->data)
        r->right = deleteBST(r->right, k);
    else
    {
        if (!r->left || !r->right)
        {
            Node *tmp = r->left ? r->left : r->right;
            free(r);
            return tmp;
        }
        Node *tmp = findMin(r->right);
        r->data = tmp->data;
        r->right = deleteBST(r->right, tmp->data);
    }
    return r;
}

// ---------- AVL Insert ----------
Node *insertAVL(Node *n, int d)
{
    if (!n)
        return createNode(d);
    if (d < n->data)
        n->left = insertAVL(n->left, d);
    else if (d > n->data)
        n->right = insertAVL(n->right, d);
    else
        return n;

    n->height = 1 + max(height(n->left), height(n->right));
    int bal = getBalance(n);

    if (bal > 1 && d < n->left->data)
        return rightRotate(n);
    if (bal < -1 && d > n->right->data)
        return leftRotate(n);
    if (bal > 1 && d > n->left->data)
    {
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }
    if (bal < -1 && d < n->right->data)
    {
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }
    return n;
}

// ---------- Menu ----------
int main()
{
    Node *bst = NULL, *avl = NULL;
    int ch, v;
    while (1)
    {
        printf("\n1.Insert BST  2.Traverse BST  3.Search  4.Delete  5.Min/Max  6.Insert AVL  7.AVL Inorder  8.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Value: ");
            scanf("%d", &v);
            bst = insertBST(bst, v);
            break;
        case 2:
            printf("Inorder: ");
            inorder(bst);
            printf("\nPreorder: ");
            preorder(bst);
            printf("\nPostorder: ");
            postorder(bst);
            printf("\n");
            break;
        case 3:
            printf("Search value: ");
            scanf("%d", &v);
            printf(search(bst, v) ? "Found\n" : "Not found\n");
            break;
        case 4:
            printf("Delete value: ");
            scanf("%d", &v);
            bst = deleteBST(bst, v);
            break;
        case 5:
            if (bst)
                printf("Min=%d Max=%d\n", findMin(bst)->data, findMax(bst)->data);
            else
                printf("Empty tree\n");
            break;
        case 6:
            printf("Value: ");
            scanf("%d", &v);
            avl = insertAVL(avl, v);
            break;
        case 7:
            printf("AVL Inorder: ");
            inorder(avl);
            printf("\n");
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
}
