/*
Write a menu-driven C program using structures to implement the following operations on a singly linked list:
> Insert an element before another specified element in the list (Example: Insert 10 before 25)
> Insert an element after another specified element in the list (Example: Insert 40 after 25)
> Delete a specified element from the list (Example: Delete node containing 15)
> Traverse the list and display all elements
> Reverse the linked list (Modify the links such that the list is reversed)
> Sort the list in ascending order (Using Bubble Sort or any appropriate algorithm on linked list)
> Delete every alternate node in the list (Starting from the second node)
> Insert an element into a sorted linked list while maintaining the sorted order (Example: Insert 28 into a list that is already sorted)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
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

Node *insert(Node *head, int data){
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
    printf("Inserted %d \n", data);
    return head;
}

void display(Node *head){
    if(head == NULL){
        printf("Empty linked list");
        return;
    } 
    printf("Linked list: ");
    Node *current = head;
    while(current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL \n");
}

Node *insertBefore(Node *head, int data, int key){

    if(head == NULL){
        printf("Error. Empty list\n");
        return head;
    }
    Node *current = head;
    Node *prev = NULL;

    while(current != NULL && current->data != key){
        prev = current;
        current = current->next;
    }
    if(current == NULL){
        printf("Key does not exist in list\n");
        return head;
    }
    Node *newNode = createNode(data);
    if(prev == NULL){
        head = newNode;
        newNode->next = current;
    } else {
        prev->next = newNode;
        newNode->next = current;
    }
    return head;
}

Node *insertAfter(Node *head, int data, int key){

    if(head == NULL){
        printf("Error. Empty list\n");
        return head;
    }
    Node *current = head;
    while(current != NULL && current->data != key){

        current = current->next;
    }
    if(current == NULL){
        printf("Key does not exist in list\n");
        return head;
    }
    Node *newNode = createNode(data);
    
    newNode->next = current->next;
    current->next = newNode;

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

Node *reverse(Node *head){
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;
    while (current != NULL) {
        next = current->next;
        
        current->next = prev;

        prev = current;
        current = next;
    }
    head = prev;
    return head;
}


int main(){

    Node *head = NULL;
    int n;
    printf("Initial no. of nodes: ");
    scanf("%d", &n);

    for(int i=0; i < n; i++){
        int data;
        printf("Enter node %d value: ", i+1);
        scanf("%d", &data);
        head = insert(head, data);
        display(head);
    }

    int key, data;
    scanf("%d", &data);
    scanf("%d", &key);

    head = insertAfter(head, data, key);
    display(head);
}
