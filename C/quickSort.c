#include<stdio.h>
#include"linkedList.h"

Node * partition(Node * first, Node * last){
    Node* pivot = first; 
    Node* front = first; 
    int temp = 0; 
    while (front != NULL && front != last) { 
        if (front->data < last->data) { 
            pivot = first; 
  
            // Swapping  node values 
            temp = first->data; 
            first->data = front->data; 
            front->data = temp; 
  
            first = first->next; 
        } 
  
        front = front->next; 
    } 
  
    // Change last node value to current node 
    temp = first->data; 
    first->data = last->data; 
    last->data = temp; 
    return pivot; 
}

void quickSort(Node *first, Node *last){
    if(first == last) return;

    Node * pivot = partition(first, last);

    if(pivot != NULL && pivot->next != NULL){
        quickSort(pivot->next, last);
    }

    if(pivot != NULL && first != pivot){
        quickSort(first, pivot);
    }
}
