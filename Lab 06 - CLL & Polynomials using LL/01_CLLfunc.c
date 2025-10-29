#include <stdio.h>
#include <stdlib.h>

#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* First = NULL;
Node* Last = NULL;

void displayList() {
    if (First == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = First;
    printf("List: ");
    do {
        if(temp == Last){
            printf(BLUE "%d\n" RESET, temp->data);
            temp = temp->next;
        }
        else {
            printf(BLUE "%d -> " RESET, temp->data);
            temp = temp->next;
        }
        
    } while (temp != First);
    //printf("(back to start)\n");
}

void insertAtEnd(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (First == NULL) {
        First = Last = newNode;
        newNode->next = First;
    } else {
        Last->next = newNode;
        Last = newNode;
        Last->next = First;
    }

    printf("\033[32mInserted %d at end.\033[0m\n", value);
    displayList();
}

void deleteFromBeginning() {
    if (First == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    Node* temp = First;

    if (First == Last) {
        First = Last = NULL;
    } else {
        First = First->next;
        Last->next = First;
    }

    free(temp);
    printf("Deleted from beginning.\n");
    displayList();
}

void deleteFromEnd() {
    if (First == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    Node* temp = First;

    if (First == Last) {
        free(First);
        First = Last = NULL;
    } else {
        while (temp->next != Last) {
            temp = temp->next;
        }
        temp->next = First;
        free(Last);
        Last = temp;
    }

    printf(RED "Deleted %d from end.\n" RESET, Last->data);
    displayList();
}

void createInitialList(int n) {
    int value;
    for (int i = 0; i < n; i++) {
        printf("\nEnter value for node %d: ", i + 1);
        scanf("%d", &value);
        insertAtEnd(value);
    }
}

int main() {
    int n, val;

    printf("Enter number of initial nodes: ");
    scanf("%d", &n);
    createInitialList(n);

    printf("\nEnter value to insert at end: ");
    scanf("%d", &val);
    insertAtEnd(val);

    deleteFromBeginning();
    deleteFromEnd();

    return 0;
}