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

Node * insertAtIndex(Node *n, int index, int value){
    Node *element = (Node *)malloc(sizeof(Node));
    check_null(element);
    element->data = value;

    if(index == -1){
        fprintf(stderr, "Index can't be negative\n");
        exit(EXIT_FAILURE);
    }

    if(NULL == n && (index != 0)){
       fprintf(stderr, "List out of range\n");
       exit(EXIT_FAILURE);
    }
    else if(NULL == n && (index == 0)){
        n = element;
        n->next = NULL;
    }
    else{
        if(index == 0){
            n = insertAtFirst(n, value);
        }
        else{
            int counter = 0;
            Node *traverse = n, *temp = NULL;
            while(counter != index-1){
                if(NULL == traverse->next){
                    fprintf(stderr,"List out of range");
                    exit(EXIT_FAILURE);
                }
                traverse = traverse->next;
                counter++;
            }
            temp = traverse->next;
            traverse->next = element;
            element->next = temp;
        }
    }
    return n;
}

Node * insertAtLast(Node *n, int value){
    Node *tail = (Node *)malloc(sizeof(Node));
    check_null(tail);
    tail->data = value;

    if(NULL == n){
        n = tail;
        n->next = NULL;

    }
    else{
        Node *traverse = n;
        while(traverse->next != NULL){
            traverse = traverse->next;
        }
        traverse->next = tail;
        tail->next = NULL;
    }
    return n;
}

Node * deleteAtFirst(Node *n){
    Node *head = NULL;

    if(NULL == n){
        fprintf(stderr,"Can't remove element from an non-existing list");
        exit(EXIT_FAILURE);
    }
    else{
        head = n->next;
        free(n);

        return head;
    }
}

int deleteAtIndex(){

}

int deleteAtLast(){

}

void printList(Node *n){
    while(n != NULL){
        printf("%d\t",n->data);
        n = n->next;
    }
}

int main()
{
    Node *n = NULL;
    // n = insertAtFirst(n, 4);
    n = deleteAtFirst(n);
    printList(n);
    return 0;
}