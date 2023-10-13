#include<stdio.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

void bubbleSort(Node *a, int size){
    int temp;
    int isSorted;
    for(int i = 0; i<size-1; i++){
        Node *nextPtr = a->next;
        Node *currentPtr = a;
        isSorted = 1;
        while(nextPtr != NULL){
            if(currentPtr->data > nextPtr->data){
                temp = nextPtr->data;
                nextPtr->data = currentPtr->data;
                currentPtr->data = temp;
                isSorted = 0;
            }
            currentPtr = nextPtr;
            nextPtr = nextPtr->next;
        }
        if(isSorted) return;
    }
}