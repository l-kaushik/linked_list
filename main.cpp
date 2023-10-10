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
   
    // Insertion 
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

    // Deletion
    // if removedValue pointer is given the removedValue will be given to it

    bool __check_null__(void *ptr){
        if(ptr == nullptr){return true;}
        return false;
    }

    bool __remove_from_beginning__(int *removedValue){
        if(__check_null__(head)){
            cerr<<"List doesn't exists"<<endl;
            return false;
        }

        Node * _mustFree = head;
        int value = _mustFree->getValue();
        head = head->getNext();
        delete _mustFree;
        if(!__check_null__(removedValue)) *removedValue = value;
        return true;
    }

    bool __remove_from_particular_index__(int index, int *removedValue){
        // if index is 0
        if(index == 0)return __remove_from_beginning__(removedValue);

        if(__check_null__(head)){
            cerr<<"List doesn't exists"<<endl;
            return false;
        }

        // index > 0 

        int counter = 0, value;
        Node * current = head, *temp = nullptr;
        while(counter != index-1){
            if(__check_null__(current)){
                cerr<<"List out of range"<<endl;
                return false;
            }
            current = current->getNext();
            counter++;
        }
        temp = current->getNext();
        if(__check_null__(temp) || __check_null__(current)){
            cerr<<"List out of range"<<endl;
            return false;
        }
        current->setNext(temp->getNext());
        value = temp->getValue();
        if(!__check_null__(removedValue))*removedValue = value;
        delete temp;
        return true;
    }

    bool __remove_from_end__(int* removedValue){
        if(__check_null__(head)){
            cerr<<"List doesn't exists"<<endl;
            return false;
        }
        int value;
        Node *current = head, *previous = nullptr;
        while(current->getNext() != nullptr){
            previous = current;
            current = current->getNext();
        }
        value = current->getValue();
        if(previous == nullptr){head = nullptr;}
        else{previous->setNext(nullptr);}
        delete current;
        if(!__check_null__(removedValue))*removedValue = value;
        return true;    
    }

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
public:
    LinkedList(){head = nullptr;}

    // INSERTION 
    void prepend(int value){__insert_at_beginning__(value);}
    void insert(int index , int value){__insert_at_index__(index, value);}
    void append(int value){ __insert_at_last__(value);}

    // DELETION
    bool removeFirst(int *removedValue=nullptr){return __remove_from_beginning__(removedValue);}
    bool removeAt(int index,int *removedValue=nullptr){return __remove_from_particular_index__(index, removedValue);}
    bool removeLast(int *removedValue=nullptr){return __remove_from_end__(removedValue);}
    
};

int main()
{
    LinkedList list;
    list.append(4);
    list.append(2);
    list.prepend(3);
    list.insert(2,99);
    cout<<list<<endl;
    int removed ;
    list.removeAt(2);
    list.removeLast();
    list.removeFirst();
    // cout<<removed<<endl;
    cout<<list<<endl;
    return 0;
}