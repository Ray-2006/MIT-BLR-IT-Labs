//bubble sort, selection sort, insertion sort

#include <stdio.h>
#include <windows.h>

int bubbleAnimation(int arr[], int size) {
    printf("Bubble Sort Animation:\n");
    printf("Original array: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\033[34mBlue for comparison\033[0m\n\033[32mGreen for swap\033[0m\n\n");
    Sleep(5000);
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            system("cls");
            for (int k = 0; k < size; k++) {
                if (k == j || k == j + 1) {
                    printf("\033[34m%d \033[0m", arr[k]);
                } else {
                    printf("%d ", arr[k]);
                }
            }
            printf("\n");
            Sleep(300);

            if (arr[j] > arr[j + 1]) {
                // Swap and print array with swap highlight
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                system("cls"); // Clear screen
                for (int k = 0; k < size; k++) {
                    if (k == j || k == j + 1) {
                        printf("\033[32m%d \033[0m", arr[k]); // Green for swap
                    } else {
                        printf("%d ", arr[k]);
                    }
                }
                printf("\n");
                Sleep(300); // Delay for animation
            }
        }
        printf("After pass %d:\n", i + 1);
        for (int k = 0; k < size; k++) {
            printf("\033[31m%d \033[0m", arr[k]);
        }
        printf("\n\n");
        Sleep(500);
    }
    return 0;
}

//selection sort animation with colors for comparison and swap
int selectionAnimation(int arr[], int size) {
    printf("Selection Sort Animation:\n");
    printf("Original array: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\033[34mBlue for comparison\033[0m\n\033[32mGreen for swap\033[0m\n\n");
    Sleep(3000);
    for (int i = 0; i < size - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < size; j++) {
            system("cls");
            for (int k = 0; k < size; k++) {
                if (k == i){
                    printf("\033[33m%d \033[0m", arr[k]);
                } else if (k == j) {
                    printf("\033[34m%d \033[0m", arr[k]);
                } else if (k == minIdx){
                    printf("\033[35m%d \033[0m", arr[k]);
                } else {
                    printf("%d ", arr[k]);
                }
            }
            printf("\n");
            Sleep(500);

            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            // Swap and print array with swap highlight
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;

            system("cls"); // Clear screen
            for (int k = 0; k < size; k++) {
                if (k == i || k == minIdx) {
                    printf("\033[32m%d \033[0m", arr[k]); // Green for swap
                } else {
                    printf("%d ", arr[k]);
                }
            }
            printf("\n");
            Sleep(500); // Delay for animation
        }
        printf("After pass %d:\n", i + 1);
        for (int k = 0; k < size; k++) {
            printf("\033[31m%d \033[0m", arr[k]);
        }
        printf("\n\n");
        Sleep(500);
    }
    return 0;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    //bubbleAnimation(arr, size);
    selectionAnimation(arr, size);

    printf("Sorted array: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

//red ansi code: \033[31m