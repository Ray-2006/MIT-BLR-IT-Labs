/*
Imagine you have a puzzle board with various puzzle pieces scattered across it. However, the puzzle board is quite large, 
and many of the spaces on the board are empty. This puzzle board can be considered as a sparse matrix. Each puzzle piece 
has a specific number value. You want to perform the following user-defined functions on this puzzle board represented as 
a sparse matrix using a singly linked list: 
    i) createSparseMatrix(): LL that contains the row, column, and value of each puzzle piece. 
    ii) addElement(head, row, col): add a value to the puzzle board by specifying its row and column.
    iii) searchElement(head, row, col): Search for a specific value on the puzzle board by providing its row and column. 
    iv) deleteElement(head, row, col): delete a value from the puzzle board by specifying its row and column.
*/

#include <stdio.h>
#include <stdlib.h>

/* ------------------- NODE STRUCTURE ------------------- */
typedef struct Node {
    int row, col, value;
    struct Node *next;
} Node;

/* ------------------- CREATE ------------------- */
Node* createSparseMatrix() {
    return NULL;   // empty matrix
}

/* ------------------- ADD ELEMENT ------------------- */
Node* addElement(Node *head, int row, int col, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;

    newNode->next = head;  // insert at front
    return newNode;        // new head
}

/* ------------------- SEARCH ELEMENT ------------------- */
Node* searchElement(Node *head, int row, int col) {
    Node *curr = head;
    while (curr != NULL) {
        if (curr->row == row && curr->col == col)
            return curr;
        curr = curr->next;
    }
    return NULL;
}

/* ------------------- DELETE ELEMENT ------------------- */
Node* deleteElement(Node *head, int row, int col) {
    Node *curr = head, *prev = NULL;

    while (curr != NULL) {
        if (curr->row == row && curr->col == col) {
            if (prev == NULL) {
                head = curr->next;   // deleting first node
            } else {
                prev->next = curr->next;
            }
            free(curr);
            return head;   // return updated head
        }
        prev = curr;
        curr = curr->next;
    }
    return head; // not found
}

/* ------------------- PRINT SPARSE MATRIX ------------------- */
void printSparseMatrix(Node *head) {
    if (head == NULL) {
        printf("Sparse Matrix is empty.\n");
        return;
    }

    printf("Sparse Matrix elements (row, col, value):\n");
    Node *curr = head;
    while (curr != NULL) {
        printf("(%d, %d) = %d\n", curr->row, curr->col, curr->value);
        curr = curr->next;
    }
}

/* ------------------- MAIN FUNCTION ------------------- */
int main() {
    Node *matrix = createSparseMatrix();

    // Adding values
    matrix = addElement(matrix, 1, 3, 5);
    matrix = addElement(matrix, 2, 4, 10);
    matrix = addElement(matrix, 4, 1, 7);

    printf("Initial Sparse Matrix:\n");
    printSparseMatrix(matrix);

    // Searching
    Node *result = searchElement(matrix, 2, 4);
    if (result)
        printf("\nFound value %d at (2, 4)\n", result->value);
    else
        printf("\nValue not found at (2, 4)\n");

    // Deleting
    printf("\nDeleting element at (1, 3)...\n");
    matrix = deleteElement(matrix, 1, 3);

    printf("\nMatrix After Deletion:\n");
    printSparseMatrix(matrix);

    return 0;
}
