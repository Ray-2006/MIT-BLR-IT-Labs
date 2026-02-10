//binary search in C

#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid; 
        }
        if (arr[mid] < target) {
            low = mid + 1; 
        } else {
            high = mid - 1; 
        }
    }
    return -1;
}

//binary search using pointers
int binarySearchPtr(int *arr, int size, int target) {
    int *low = arr;
    int *high = arr + size - 1;

    while (low <= high) {
        int *mid = low + (high - low) / 2;

        if (*mid == target) {
            return mid - arr; 
        }
        if (*mid < target) {
            low = mid + 1; 
        } else {
            high = mid - 1; 
        }
    }
    return -1;
}

//binary search using recursion
int binarySearchRec(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1; 
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == target) {
        return mid; 
    }
    if (arr[mid] < target) {
        return binarySearchRec(arr, mid + 1, high, target); 
    } else {
        return binarySearchRec(arr, low, mid - 1, target); 
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Enter the number to search: ");
    scanf("%d", &target);

    int result = binarySearch(arr, size, target);
    int resultPtr = binarySearchPtr(arr, size, target);
    int resultRec = binarySearchRec(arr, 0, size - 1, target);

    printf("%d", resultPtr);
    printf("%d", resultRec);

    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}