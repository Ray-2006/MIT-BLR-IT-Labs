#include <stdio.h>
#include <stdlib.h>

void multiplyMatrices(int *A, int *B, int *C, int r1, int c1, int c2) {
    // C = A (r1 x c1) * B (c1 x c2)
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            *(C + i*c2 + j) = 0;  // initialize result
            for (int k = 0; k < c1; k++) {
                *(C + i*c2 + j) += (*(A + i*c1 + k)) * (*(B + k*c2 + j));
            }
        }
    }
}

void printMatrix(int *M, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", *(M + i*cols + j));
        }
        printf("\n");
    }
}

int main() {
    int r1, c1, r2, c2;

    printf("Enter rows and cols of Matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and cols of Matrix B: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Matrix multiplication not possible! (c1 must equal r2)\n");
        return 1;
    }

    int *A = (int *)malloc(r1 * c1 * sizeof(int));
    int *B = (int *)malloc(r2 * c2 * sizeof(int));
    int *C = (int *)malloc(r1 * c2 * sizeof(int));

    printf("Enter elements of Matrix A (%d x %d):\n", r1, c1);
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            scanf("%d", (A + i*c1 + j));
    
    /* 
    r1 = 3, c1 = 3
    A[i][j] is accessed as *(A + i*c1 + j)
    A[2][2] = *(A + 2*3 + 2); = *(A + 8);
    A[0][0] A[0][1] A[0][2] A[1][0] A[1][1] A[1][2] A[2][0] A[2][1] A[2][2]
    */

    printf("Enter elements of Matrix B (%d x %d):\n", r2, c2);
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            scanf("%d", (B + i*c2 + j));

    multiplyMatrices(A, B, C, r1, c1, c2);

    printf("\nResult Matrix (A x B):\n");
    printMatrix(C, r1, c2);

    free(A);
    free(B);
    free(C);

    return 0;
}
