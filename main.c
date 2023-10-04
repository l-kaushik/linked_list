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

void insertAtFirst(Node * n, int value){
    Node *head = (Node *)malloc(sizeof(Node));
    check_null(n);
    if(NULL == n){
        n->data = value;
    }
    else{
        head->next = n;
        n = head;
    }
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
    Node *n;
    insertAtFirst(n, 4);
    printf("%d",n->data);
    return 0;
}