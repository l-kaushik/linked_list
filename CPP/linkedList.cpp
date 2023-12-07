#include<iostream>
#include"linkedList.hpp"

// Insertion
void LinkedList::__insert_at_beginning__(int value)
{
    Node *newNode = new Node(value, head);
    head = newNode;
}

void LinkedList::__insert_at_index__(int index, int value)
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
        Node *current = head, *temp;
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
        current->setNext(new Node(value, temp));
    }
}

void LinkedList::__insert_at_last__(int value)
{
    if (head == nullptr)
    {
        head = new Node(value, nullptr);
    }
    else
    {
        Node *current = head;
        while (current->getNext() != nullptr)
        {
            current = current->getNext();
        }
        current->setNext(new Node(value));
    }
}

std::istream &operator>>(std::istream &is, LinkedList &list)
{
    int value;
    is >> value;
    list.__insert_at_last__(value);
    return is;
}

// Deletion
// if removedValue pointer is given the removedValue will be given to it

bool LinkedList::__check_null__(void *ptr)
{
    if (ptr == nullptr)
    {
        return true;
    }
    return false;
}

bool LinkedList::__remove_from_beginning__(int *removedValue)
{
    if (__check_null__(head))
    {
        std::cerr << "List doesn't exists" << std::endl;
        return false;
    }

    Node *_mustFree = head;
    int value = _mustFree->getValue();
    head = head->getNext();
    delete _mustFree;
    if (!__check_null__(removedValue))
        *removedValue = value;
    return true;
}

bool LinkedList::__remove_from_particular_index__(int index, int *removedValue)
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

    int counter = 0, value;
    Node *current = head, *temp = nullptr;
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

bool LinkedList::__remove_from_end__(int *removedValue)
{
    if (__check_null__(head))
    {
        std::cerr << "List doesn't exists" << std::endl;
        return false;
    }
    int value;
    Node *current = head, *previous = nullptr;
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
std::ostream &operator<<(std::ostream &os, const LinkedList &list)
{
    Node *current = list.head;

    while (current != nullptr)
    {
        os << current->getValue();
        current = current->getNext();
        if (current != nullptr)
            os << " ";
    }
    return os;
}
