#include<stdio.h>
#include<stdlib.h>
#include "sortingalgo.h"

typedef struct Node{
    int data;
    struct Node *next;
} Node;

// function prototyping
void check_null(Node *, void *, char *);
Node * insertAtFirst(Node *, int );
Node * insertAtIndex(Node *, int , int );
Node * insertAtLast(Node *, int );
Node * prepend(Node *, int);
Node * insert(Node *, int, int );
Node * append(Node *, int);
Node * deleteFirst(Node *);
Node * deleteAt(Node *, int );
Node * deleteLast(Node *);
Node * delete(Node *);
int length(Node *);
void printList(Node *);
void freeList(Node *);

void check_null(Node * head, void *ptr, char *msg){
    if(NULL == ptr){
        fprintf(stderr, msg);
        freeList(head);
        exit(EXIT_FAILURE);
    }
}

// insertion operations

Node * insertAtFirst(Node * n, int value){
    Node *head = (Node *)malloc(sizeof(Node));
    check_null(n, head, "Memory can't be allocated\n");
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

Node * insertAtIndex(Node *head, int index, int value){
    Node *element = (Node *)malloc(sizeof(Node));
    check_null(head, element, "Memory can't be allocated\n");
    element->data = value;

    if(index < 0){
        check_null(head, NULL, "Index can't be negative\n");
    }
    else if(NULL == head && (index != 0)){
        check_null(head,NULL,"List doesn't exists\n");
    }
    else if(NULL == head && (index == 0)){
        head = element;
        head->next = NULL;
        return head;
    }
    else{
        if(index == 0){
            head = insertAtFirst(head, value);
        }
        else{
            int counter = 0;
            Node *traverse = head, *temp = NULL;
            while(counter != index-1){
                check_null(head, traverse->next, "List out of range\n");
                traverse = traverse->next;
                counter++;
            }
            temp = traverse->next;
            traverse->next = element;
            element->next = temp;
        }
    }
    return head;
}


Node * insertAtLast(Node *head, int value){
    Node *tail = (Node *)malloc(sizeof(Node));
    check_null(head, tail, "Memory can't be allocated\n");
    tail->data = value;

    if(NULL == head){
        head = tail;
        head->next = NULL;
    }
    else{
        Node *traverse = head;
        while(traverse->next != NULL){
            traverse = traverse->next;
        }
        traverse->next = tail;
        tail->next = NULL;
    }
    return head;
}

Node * prepend(Node *head, int value){
    Node *newHead = insertAtFirst(head, value);
    return newHead;
}
Node * insert(Node *head, int index, int value){
    Node *newHead = insertAtIndex(head, index, value);
    return newHead;
}
Node * append(Node *head, int value){
    Node *newHead = insertAtLast(head, value);
    return newHead;
}

// deletion operations

Node * deleteFirst(Node *head){
    Node *newHead = NULL;

    check_null(head, head, "List doesn't exists");

    newHead = head->next;
    free(head);

    return newHead;
}

Node * deleteAt(Node *head, int index){
    check_null(head, head, "List doesn't exists\n");
    
    if(index < 0){
        check_null(head, NULL, "Index can't be negative");
    }
    else if(index == 0){
        head = deleteFirst(head);
    }
    else{
        int counter = 0;
        Node *traverse = head, *temp = NULL;
        while(counter != index-1){
            check_null(head, traverse->next, "List out of range\n");
            traverse = traverse->next;
            counter++;
        }
        temp = traverse->next;
        check_null(head, temp, "List out of range\n");
        traverse->next = temp->next;
        free(temp);
    }
    return head;
}

Node * deleteLast(Node *head){
    Node * temp = head, *tail = NULL;

    while(temp->next != NULL){
        tail = temp;
        temp = temp->next;
    }
    free(temp);
    if(NULL == tail){
        return NULL;
    }
    tail->next = NULL;

    return head;
}

Node * delete(Node *head){
    Node * newHead = deleteLast(head);
    return newHead;
}

int length(Node *head){
    int count = 0;
    while (head != NULL)
    {
        head = head->next;
        count++;
    }
    return count;  
}

void printList(Node *head){
    while(head != NULL){
        printf("%d\t",head->data);
        head = head->next;
    }
}

void freeList(Node *head){
    while(head != NULL){
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    Node *n = NULL;
    n = append(n,4);
    n = prepend(n,8);
    n = insert(n,0,4);
    n = prepend(n,23);
    n = prepend(n,32);
    n = prepend(n,64);
    // n = deleteFirst(n);
    printList(n);
    printf("\n%d",length(n));
    freeList(n);
    return 0;
}