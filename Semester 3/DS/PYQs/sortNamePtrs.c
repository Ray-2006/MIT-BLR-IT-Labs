#include <stdio.h>
#include <string.h>

int main() {
    int n;
    printf("Enter number of names: ");
    scanf("%d", &n);

    char names[n][50];      // stores actual names
    char *ptr[n];           // array of pointers to names

    printf("\nEnter the names:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]); 
        ptr[i] = names[i];      // pointer points to each name
    }

    /* ------ Sorting using pointer array ------ */
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(ptr[i], ptr[j]) > 0) {
                char *temp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = temp;
            }
        }
    }

    /* ------ Display in sorted order ------ */
    printf("\nSorted Names:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", ptr[i]);
    }

    return 0;
}
