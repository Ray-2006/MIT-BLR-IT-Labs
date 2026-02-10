// create array using ptr
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for n integers
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Input elements
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print elements
    printf("You entered:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free allocated memory
    free(arr);
    return 0;
}


// int *a = arr[3]
// printf("%d", a); // prints address of arr[0]
// printf("%d", *a); // prints arr[0]
// printf("%d", *(a+1)); // prints arr[1]

//for 2d
// int *a = arr[3][3]
// printf("%d", a); // prints address of arr[0][0]
// printf("%d", *a); // prints arr[0][0]
// printf("%d", *(a+1)); // prints arr[0][1]
// printf("%d", *(a+3)); // prints arr[1][0]
// printf("%d", *(a+4)); // prints arr[1][1]

// function to print 2d array using ptr
// void print2D(int *a, int rows, int cols) {
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             printf("%d ", *(a + i*cols + j));
//         }
//         printf("\n");
//     }
// }