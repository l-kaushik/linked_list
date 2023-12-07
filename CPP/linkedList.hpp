#pragma once
#include <iostream>

class Node
{
private:
    int data;
    Node *next;

public:
    Node(int value, Node *next = nullptr) : data(value), next(next){}

    int getValue() { return this->data; }
    Node *getNext() { return this->next; }
    void setNext(Node *next) { this->next = next; }
};

class LinkedList
{
private:
    Node *head;

    void __insert_at_beginning__(int);
    void __insert_at_index__(int , int );
    void __insert_at_last__(int );
    friend std::istream &operator>>(std::istream &, LinkedList &);
    bool __check_null__(void *);
    bool __remove_from_beginning__(int *);
    bool __remove_from_particular_index__(int, int*);
    bool __remove_from_end__(int *);
    friend std::ostream &operator<<(std::ostream &os, const LinkedList &list);

public:
    // constructor
    LinkedList() : head(nullptr){}

    // destructor
    ~LinkedList(){
        while(head != nullptr)
            removeLast();
    }

    // INSERTION
    void prepend(int value) { __insert_at_beginning__(value); }
    void insert(int index, int value) { __insert_at_index__(index, value); }
    void append(int value) { __insert_at_last__(value); }

    // DELETION
    bool removeFirst(int *removedValue = nullptr) { return __remove_from_beginning__(removedValue); }
    bool removeAt(int index, int *removedValue = nullptr) { return __remove_from_particular_index__(index, removedValue); }
    bool removeLast(int *removedValue = nullptr) { return __remove_from_end__(removedValue); }
};
