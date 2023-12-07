#include<stdio.h>
#include"linkedList.h"

void selectionSort(Node *head){
    Node *traverse = head;
    Node *min = NULL, *nextPtr = NULL;
    int temp;

    while(traverse->next != NULL){
        min = traverse;
        nextPtr = traverse->next;

        while(nextPtr != NULL){
            if (min->data > nextPtr->data)
                min = nextPtr;
            nextPtr = nextPtr->next;
        }
        temp = traverse->data;
        traverse->data = min->data;
        min->data = temp;

        traverse = traverse->next;
    }
}
