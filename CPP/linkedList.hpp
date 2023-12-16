#pragma once
#include <iostream>

template <typename T>
class Node
{
private:
    T m_data;
    Node<T> *m_next;

public:
    Node(T data, Node<T> *next = nullptr) : m_data(data), m_next(next){}

    T getValue() { return m_data; }
    Node<T> *getNext() { return m_next; }
    void setNext(Node<T> *next) { m_next = next; }
};

template <typename T>
class LinkedList
{
private:
    Node<T> *head;

    void __insert_at_beginning__(T);
    void __insert_at_index__(int , T );
    void __insert_at_last__(T );
    template<class U> friend std::istream &operator>>(std::istream &, LinkedList<U> &);
    bool __check_null__(void *);
    bool __remove_from_beginning__(T *);
    bool __remove_from_particular_index__(int, T*);
    bool __remove_from_end__(T *);
    template<class U> friend std::ostream &operator<<(std::ostream &, const LinkedList<U> &);

public:
    // constructor
    LinkedList() : head(nullptr){}

    // destructor
    ~LinkedList(){
        while(head != nullptr)
            removeLast();
    }

    // INSERTION
    void prepend(T value) { __insert_at_beginning__(value); }
    void insert(int index, T value) { __insert_at_index__(index, value); }
    void append(T value) { __insert_at_last__(value); }

    // DELETION
    bool removeFirst(T *removedValue = nullptr) { return __remove_from_beginning__(removedValue); }
    bool removeAt(int index, T *removedValue = nullptr) { return __remove_from_particular_index__(index, removedValue); }
    bool removeLast(T *removedValue = nullptr) { return __remove_from_end__(removedValue); }
};

// Insertion
template <typename T>
void LinkedList<T>::__insert_at_beginning__(T value)
{
    Node<T> *newNode = new Node<T>(value, head);
    head = newNode;
}

template <typename T>
void LinkedList<T>::__insert_at_index__(int index, T value)
{
    try
    {
        if (index < 0)
            throw std::invalid_argument("Index cannot be negative.");
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }

    if (index == 0)
        __insert_at_beginning__(value);
    else
    {
        int counter = 0;
        Node<T> *current = head, *temp;
        while (counter != index - 1)
        {
            try
            {
                if (current->getNext() == nullptr)
                    throw std::out_of_range("List is out of range");
            }
            catch (const std::exception &e)
            {
                std::cerr << "Error: " << e.what() << std::endl;
                exit(EXIT_FAILURE);
            }
            current = current->getNext();
            counter++;
        }
        temp = current->getNext();
        current->setNext(new Node<T>(value, temp));
    }
}

template <typename T>
void LinkedList<T>::__insert_at_last__(T value)
{
    if (head == nullptr)
    {
        head = new Node<T>(value, nullptr);
    }
    else
    {
        Node<T> *current = head;
        while (current->getNext() != nullptr)
        {
            current = current->getNext();
        }
        current->setNext(new Node<T>(value));
    }
}

template <typename T>
std::istream &operator>>(std::istream &is, LinkedList<T> &list)
{
    T value;
    is >> value;
    list.__insert_at_last__(value);
    return is;
}

// Deletion
// if removedValue pointer is given the removedValue will be given to it
template <typename T>
bool LinkedList<T>::__check_null__(void *ptr)
{
    if (ptr == nullptr)
    {
        return true;
    }
    return false;
}

template <typename T>
bool LinkedList<T>::__remove_from_beginning__(T *removedValue)
{
    if (__check_null__(head))
    {
        std::cerr << "List doesn't exists" << std::endl;
        return false;
    }

    Node<T> *_mustFree = head;
    T value = _mustFree->getValue();
    head = head->getNext();
    delete _mustFree;
    if (!__check_null__(removedValue))
        *removedValue = value;
    return true;
}

template <typename T>
bool LinkedList<T>::__remove_from_particular_index__(int index, T *removedValue)
{
    // if index is 0
    if (index == 0)
        return __remove_from_beginning__(removedValue);

    if (__check_null__(head))
    {
        std::cerr << "List doesn't exists" << std::endl;
        return false;
    }

    // index > 0

    int counter = 0;
    T value;
    Node<T> *current = head, *temp = nullptr;
    while (counter != index - 1)
    {
        if (__check_null__(current))
        {
            std::cerr << "List out of range" << std::endl;
            return false;
        }
        current = current->getNext();
        counter++;
    }
    temp = current->getNext();
    if (__check_null__(temp) || __check_null__(current))
    {
        std::cerr << "List out of range" << std::endl;
        return false;
    }
    current->setNext(temp->getNext());
    value = temp->getValue();
    if (!__check_null__(removedValue))
        *removedValue = value;
    delete temp;
    return true;
}

template <typename T>
bool LinkedList<T>::__remove_from_end__(T *removedValue)
{
    if (__check_null__(head))
    {
        std::cerr << "List doesn't exists" << std::endl;
        return false;
    }
    T value;
    Node<T> *current = head, *previous = nullptr;
    while (current->getNext() != nullptr)
    {
        previous = current;
        current = current->getNext();
    }
    value = current->getValue();
    if (previous == nullptr)
    {
        head = nullptr;
    }
    else
    {
        previous->setNext(nullptr);
    }
    delete current;
    if (!__check_null__(removedValue))
        *removedValue = value;
    return true;
}

// OUTPUT
template <typename T>
std::ostream &operator<<(std::ostream &os, const LinkedList<T> &list)
{
    Node<T> *current = list.head;

    while (current != nullptr)
    {
        os << current->getValue();
        current = current->getNext();
        if (current != nullptr)
            os << " ";
    }
    return os;
}

