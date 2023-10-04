#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    int size;
    struct Node *next;
} Node;

void check_null(void *ptr){
    if(NULL == ptr){
        fprintf(stderr, "Memory can't be allocated\n");
        exit(EXIT_FAILURE);
    }
}

Node * createNode(){
    Node *n = (Node *)malloc(sizeof(Node));
    check_null(n);
    n->data = 0;
    n->size = -1;   // -1 means node is empty
    n->next = NULL;

    return n;
}

void insertAtFirst(Node * n, int value){
    
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
    Node *n = createNode();
    printf("%d",n->data);
    return 0;
}