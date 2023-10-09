#include<iostream>

using namespace std;


class Node{
private:
    int data;
    Node* next;
public:
    Node(int value, Node* next = nullptr){
        this->data = value;
        this->next = next;
    }

    int getValue(){return this->data;}
    Node *getNext(){return this->next;}
    void setNext(Node *next){this->next = next;}
};

class LinkedList{
private:
    Node *head;
public:
    LinkedList(){head = nullptr;}

    void insertAtLast(int value){
        if(head == nullptr){
            head = new Node(value, nullptr);
        }
        else{
            Node *current = head;
            while(current->getNext() != nullptr){
                current = current->getNext();
            }
            current->setNext(new Node(value));
        }
    }

    void printArray(){
        Node *current = head;
        while(current != nullptr){
            cout<<current->getValue();
            current = current->getNext();
            if(current != nullptr){cout<<" ";}
        }
    }

    friend ostream& operator<<(ostream& os, const LinkedList& list) {
        Node *current = list.head;

        while(current != nullptr){
            os << current->getValue();
            current = current->getNext();
            if(current != nullptr) os <<" ";
        }
        return os;
    }

   friend istream& operator>>(istream& is, LinkedList& list){
        int value;
        is>>value;
        list.insertAtLast(value);
        return is;
    }
};
int main()
{
    LinkedList list;
    // list.insertAtLast(4);
    // list.insertAtLast(2);
    // list.insertAtLast(3);
    cin>>list>>list>>list>>list;
    // list.printArray();
    cout<<list;

    return 0;
}