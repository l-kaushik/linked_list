#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

void check_null(void *ptr){
    if(NULL == ptr){
        fprintf(stderr, "Memory can't be allocated\n");
        exit(EXIT_FAILURE);
    }
}

Node * insertAtFirst(Node * n, int value){
    Node *head = (Node *)malloc(sizeof(Node));
    check_null(head);
    head->data = value;

    if(NULL == n){
      n = head;
      n->next = NULL;
    }
    else{
        head->next = n;
        n = head;
    }
    return n;
}

void insertAtIndex(){
    //
}

void insertAtLast(){
    // 
}

int deleteAtFirst(){
    //
}

int deleteAtIndex(){

}

int deleteAtLast(){

}

int main()
{
    Node *n = NULL;
    n = insertAtFirst(n, 4);
    n = insertAtFirst(n, 9);
    printf("%d\t%d",n->data, n->next->data);
    return 0;
}