/*1.
Write a small function to find the smallest element in an array using pointers.
In the main function, create a dynamically allocated array, read the values from the keyboard, and pass the array to the function.
Display the result (smallest element) in the main function.
*/

#include <stdio.h>
#include <stdlib.h>

int findSmallest(int *arr, int size) {
    int min = *arr;
    for (int i = 1; i < size; i++) {
        if (*(arr + i) < min) {
            min = *(arr + i);
        }
    }
    return min;
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

    int smallest = findSmallest(arr, n);
    printf("Smallest element is: %d\n", smallest);

    free(arr);
    return 0;
}