#include<stdio.h>
#include "linkedList.h"

void bubbleSort(Node *a, int size){
    int temp;
    int isSorted;
    for(int i = 0; i<size-1; i++){  // loop for each pass
        Node *nextPtr = a->next;
        Node *currentPtr = a;
        isSorted = 1;
        for(int j = 0; j < size-i-1; j++){  // loop for lowest possible no. of comparisons in each pass
            if(currentPtr->data > nextPtr->data){
                temp = nextPtr->data;
                nextPtr->data = currentPtr->data;
                currentPtr->data = temp;
                isSorted = 0;
            }
            currentPtr = nextPtr;
            nextPtr = nextPtr->next;
        }
        if(isSorted) return;    // sorted flag for O(n) time complexity
    }
}
