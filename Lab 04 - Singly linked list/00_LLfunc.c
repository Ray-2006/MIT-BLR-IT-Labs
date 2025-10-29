#include <stdio.h>
#include <stdlib.h>

#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node *insert(Node *head, int data) {
    Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    }
    else {
        Node *current = head;
        while (current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
    printf(GREEN "Inserted %d \n" RESET, data);
    return head;
}

Node *delete(Node *head, int data){
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return NULL;
    }
    Node *current = head;
    Node *prev = NULL;
    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Element not found in the linked list.\n");
        return head;
    }
    if (prev == NULL) {
        head = current->next;
    }
    else {
        prev->next = current->next;
    }
    free(current);
    printf("Element deleted successfully.\n");
    return head;
}

void display(Node *head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    Node *current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf(BLUE "%d -> " RESET, current->data);
        current = current->next;
    }
    printf(BLUE "NULL\n" RESET);
}

int main(){
    Node *head = NULL;
    int choice, data;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display the linked list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                head = insert(head, data);
                display(head);
                break;
            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                head = delete(head, data);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}
