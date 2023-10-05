#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

void check_null(void *ptr, char *msg){
    if(NULL == ptr){
        fprintf(stderr, msg);
        exit(EXIT_FAILURE);
    }
}

// insertion operations

Node * insertAtFirst(Node * n, int value){
    Node *head = (Node *)malloc(sizeof(Node));
    check_null(head, "Memory can't be allocated\n");
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
    check_null(element, "Memory can't be allocated\n");
    element->data = value;

    if(index == -1){
        check_null(NULL, "Index can't be negative\n");
    }

    if(NULL == n && (index != 0)){
       check_null(NULL, "List out of range\n");
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
                check_null(traverse->next, "List out of range\n");
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
    check_null(tail, "Memory can't be allocated\n");
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

Node * insert(Node *n, int value){
    Node *temp = insertAtLast(n, value);
    return temp;
}

// deletion operations

Node * deleteAtFirst(Node *n){
    Node *head = NULL;

    check_null(n, "List doesn't exists");

    head = n->next;
    free(n);

    return head;
}

Node * deleteAtIndex(Node *n, int index){
    check_null(n, "List doesn't exists\n");
    
    if(index < 0){
        check_null(NULL, "Index can't be negative");
    }
    else if(index == 0){
        n = deleteAtFirst(n);
    }
    else{
        int counter = 0;
        Node *traverse = n, *temp = NULL;
        while(counter != index-1){
            check_null(traverse->next, "List out of range\n");
            traverse = traverse->next;
            counter++;
        }
        temp = traverse->next;
        check_null(temp, "List out of range\n");
        traverse->next = temp->next;
    }
    return n;
}

Node * deleteAtLast(Node *n){
    Node * temp = n, *temp2 = NULL;

    while(temp->next != NULL){
        temp2 = temp;
        temp = temp->next;
    }
    free(temp);
    if(NULL == temp2){
        return NULL;
    }
    temp2->next = NULL;

    return n;
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
    n = insert(n, 4);
    n = insert(n, 8);
    n = deleteAtIndex(n, -1);
    printList(n);
    return 0;
}