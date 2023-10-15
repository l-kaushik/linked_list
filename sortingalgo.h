#ifndef SORTINGALGO_H
#define SORTINGALGO_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

//function prototypes
void bubbleSort(Node *, int);
void selectionSort(Node *);
void quickSort(Node *, Node *);
#endif