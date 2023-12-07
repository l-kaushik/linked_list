#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// sorting functions
void bubbleSort(Node *, int);
void selectionSort(Node *);
void quickSort(Node *, Node *);

// linked list functions
void check_null(Node *, void *, char *);
Node * insertAtFirst(Node *, int );
Node * insertAtIndex(Node *, int , int );
Node * insertAtLast(Node *, int );
Node * prepend(Node *, int);
Node * insert(Node *, int, int );
Node * append(Node *, int);
Node * deleteFirst(Node *);
Node * deleteAt(Node *, int );
Node * deleteLast(Node *);
Node * delete(Node *);
Node * lastNode(Node *);
int length(Node *);
void printList(Node *);
void freeList(Node *);

#endif
