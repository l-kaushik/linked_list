#include<stdio.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

void bubbleSort(Node *a, int size){
    int temp;

    for(int i = 0; i<size-1; i++){
        Node *nextPtr = a->next;
        Node *currentPtr = a;
        while(nextPtr != NULL){
            if(currentPtr->data > nextPtr->data){
                temp = nextPtr->data;
                nextPtr->data = currentPtr->data;
                currentPtr->data = temp;
            }
            currentPtr = nextPtr;
            nextPtr = nextPtr->next;
        }
    }
}