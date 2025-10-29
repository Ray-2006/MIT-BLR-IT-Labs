#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node *head=NULL, *tail=NULL;

Node* createNode(int x) {
    Node* n=(Node*)malloc(sizeof(Node));
    n->data=x; n->prev=n->next=NULL;
    return n;
}

// Insert rear
void insertRear(int x) {
    Node* n=createNode(x);
    if (!head) head=tail=n;
    else { tail->next=n; n->prev=tail; tail=n; }
}

// Delete rear
void deleteRear() {
    if (!tail) { printf("Empty\n"); return; }
    Node* t=tail;
    if (head==tail) head=tail=NULL;
    else { tail=tail->prev; tail->next=NULL; }
    free(t);
}

// Insert at position
void insertAtPos(int x,int pos) {
    if (pos<=0) return;
    Node* n=createNode(x);
    if (pos==1) {
        n->next=head; if (head) head->prev=n; head=n;
        if (!tail) tail=n; return;
    }
    Node* t=head;
    for (int i=1; t && i<pos-1; i++) t=t->next;
    if (!t) { free(n); return; }
    n->next=t->next; n->prev=t;
    if (t->next) t->next->prev=n; else tail=n;
    t->next=n;
}

// Delete at position
void deleteAtPos(int pos) {
    if (pos<=0||!head) return;
    Node* t=head;
    if (pos==1) {
        head=head->next; if (head) head->prev=NULL; else tail=NULL;
        free(t); return;
    }
    for (int i=1; t && i<pos; i++) t=t->next;
    if (!t) return;
    if (t->prev) t->prev->next=t->next;
    if (t->next) t->next->prev=t->prev; else tail=t->prev;
    free(t);
}

// Insert after value
void insertAfter(int x,int v) {
    Node* t=head; while (t && t->data!=v) t=t->next;
    if (!t) return;
    Node* n=createNode(x);
    n->next=t->next; n->prev=t;
    if (t->next) t->next->prev=n; else tail=n;
    t->next=n;
}

// Insert before value
void insertBefore(int x,int v) {
    Node* t=head; while (t && t->data!=v) t=t->next;
    if (!t) return;
    Node* n=createNode(x);
    n->next=t; n->prev=t->prev;
    if (t->prev) t->prev->next=n; else head=n;
    t->prev=n;
}

// Traversals
void forward() { for(Node* t=head;t;t=t->next) printf("%d ",t->data); printf("\n"); }
void reverse() { for(Node* t=tail;t;t=t->prev) printf("%d ",t->data); printf("\n"); }

int main() {
    int c,x,p,v;
    while(1) {
        printf("\n1.InsertRear 2.DeleteRear 3.InsertPos 4.DeletePos\n");
        printf("5.InsertAfter 6.InsertBefore 7.Forward 8.Reverse 9.Exit\n");
        scanf("%d",&c);
        switch(c) {
            case 1: scanf("%d",&x); insertRear(x); break;
            case 2: deleteRear(); break;
            case 3: scanf("%d%d",&x,&p); insertAtPos(x,p); break;
            case 4: scanf("%d",&p); deleteAtPos(p); break;
            case 5: scanf("%d%d",&x,&v); insertAfter(x,v); break;
            case 6: scanf("%d%d",&x,&v); insertBefore(x,v); break;
            case 7: forward(); break;
            case 8: reverse(); break;
            case 9: return 0;
        }
    }
}
