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

    // INSERTION OPERATION

    // implementation

    void __insert_at_beginning__(int value){
        Node *newNode = new Node(value, head);
        head = newNode;
    }

    void __insert_at_index__(int index, int value){
        try{
            if(index < 0) throw invalid_argument("Index cannot be negative.");
        } catch (const exception& e){
            cerr<<"Error: "<<e.what()<<endl;
            exit(EXIT_FAILURE);
        }

        if(index == 0) __insert_at_beginning__(value);
        else{
            int counter = 0;
            Node *current = head, *temp;
            while(counter != index-1){
                try{
                    if(current->getNext() == nullptr) throw out_of_range("List is out of range");
                }catch(const exception& e){
                    cerr<<"Error: "<<e.what()<<endl;
                    exit(EXIT_FAILURE);
                }
                current = current->getNext();
                counter++;
            }
            temp = current->getNext();
            current->setNext(new Node(value,temp));
        }
    }

    void __insert_at_last__(int value){
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

    friend istream& operator>>(istream& is, LinkedList& list){
        int value;
        is>>value;
        list.__insert_at_last__(value);
        return is;
    }
    
    // functions to be called
    void prepend(int value){__insert_at_beginning__(value);}
    void insert(int index , int value){__insert_at_index__(index,  value);}
    void append(int value){ __insert_at_last__(value);}

    // DELETION

    int __remove_from_beginning__(){}
    int __remove_from_particular_index__(int index){}
    int __remove_from_end__(){}

    // functions to be called
    int removeFirst(){__remove_from_beginning__();}
    int removeAt(int index){__remove_from_particular_index__(index);}
    int removeLast(){__remove_from_end__();}

    // OUTPUT
    friend ostream& operator<<(ostream& os, const LinkedList& list) {
        Node *current = list.head;

        while(current != nullptr){
            os << current->getValue();
            current = current->getNext();
            if(current != nullptr) os <<" ";
        }
        return os;
    }

};
int main()
{
    LinkedList list;
    list.append(4);
    list.append(2);
    list.prepend(3);
    list.insert(-1,99);
    cout<<list;

    return 0;
}