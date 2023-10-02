#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    int size;
    struct Node *next;
} Node;

Node * createNode(){
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = 0;
    n->size = -1;
    n->next = NULL;

    return n;
}

int main()
{
    Node *n = createNode();
    printf("%d",n->data);
    return 0;
}