#include <stdlib.h>
#include <stdio.h>

int arr[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

void printMatrix(int (*p)[3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", *(*(p + i) + j));
        }
        printf("\n");
    }
}

void printMatrix2(int *M, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", *(M + i*cols + j));
        }
        printf("\n");
    }
}

int main() {
    printf("Using int (*)[3]:\n");
    printMatrix(arr, 3, 3);
    printf("Using int *:\n");
    printMatrix2((int *)arr, 3, 3);
    return 0;
}