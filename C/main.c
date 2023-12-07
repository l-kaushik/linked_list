#include<stdio.h>
#include<stdlib.h>
#include "linkedList.h"

int main()
{
    Node *head = NULL;
    for(int i = 1; i<10; i++){
        head = append(head,rand()%100);
    }
    printList(head);
    quickSort(head, lastNode(head));
    printf("\n\n");
    printList(head);
    freeList(head);
    return 0;
}
