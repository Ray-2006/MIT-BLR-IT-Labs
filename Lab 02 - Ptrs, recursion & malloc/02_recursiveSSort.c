/*
Write a recursive C program to implement Selection Sort using pointers.
The recursive function should sort the array using the Selection Sort algorithm.
Access and manipulate the array elements using pointers (i.e., avoid using arr[i] style directly).
The program should read the array from the user in the main function, call the recursive sorting function, and display the sorted array.
*/

#include <stdio.h>
#include <stdlib.h>

void sort(int *arr, int n, int index) {
    if (index >= n - 1) return;

    int minIndex = index;
    for (int j = index + 1; j < n; j++) {
        if (*(arr + j) < *(arr + minIndex)) {
            minIndex = j;
        }
    }

    if (minIndex != index) {
        int temp = *(arr + index);
        *(arr + index) = *(arr + minIndex);
        *(arr + minIndex) = temp;
    }

    sort(arr, n, index + 1);
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    sort(arr, n, 0);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    free(arr);
    return 0;
}