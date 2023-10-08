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


int main()
{
    Node a = 4;
    cout<<a.getValue();
    return 0;
}