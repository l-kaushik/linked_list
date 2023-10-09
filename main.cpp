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
    // if returnFlag is > 0 then return the deleted value and in case of error return -1
    // if returnFlag is 0 then return 0 on success and 1 on failure

    int __check_head_for_remove__(int returnFlag){
        try{
            if(head == nullptr) throw range_error("List is empty");
        }
        catch(const exception& e){
            cerr<<"Error: "<<e.what()<<endl;
            if(returnFlag > 0) return -1;
            else return 1;
        }
        return 0;
    }

    int __remove_from_beginning__(int returnFlag){
        int _checkNull = __check_head_for_remove__(returnFlag);
        if (_checkNull != 0){return _checkNull;}

        Node * _mustFree = head;
        int value = _mustFree->getValue();
        head = head->getNext();
        delete _mustFree;
        if(returnFlag > 0) return value;
        else return 0;
    }

    int __remove_from_particular_index__(int index,int returnFlag){
        int _checkNull = __check_head_for_remove__(returnFlag);
        if(_checkNull != 0){return _checkNull;}

        // if index is one calling the function rather then adding an explicit code for that situation
        if(index == 0) return __remove_from_beginning__(returnFlag);

        int counter = 0, value;
        Node *current = head, *temp;
        while(counter != index-1){
            try{
                if(current->getNext() == nullptr) throw out_of_range("List is out of range");
            }catch(const exception& e){
                cerr<<"Error: "<<e.what()<<endl;
                if(returnFlag > 0) return -1;
                else return 1;
            }
            current = current->getNext();
            counter++;
        }
        temp = current->getNext();
        try{
            if(temp == nullptr) throw out_of_range("List is out of range");
        }catch(const exception& e){
            cerr<<"Error: "<<e.what()<<endl;
            if(returnFlag > 0)return -1;
            else return 1;
        }
        current->setNext(temp->getNext());
        value = temp->getValue();
        delete temp;
        if(returnFlag > 0) return value;
        else return 0;
    }

    int __remove_from_end__(int returnFlag){
        Node *current = head;
        while(current->getNext() != nullptr){
            current = current->getNext();
        }
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
    int removeFirst(int returnFlag=0){return __remove_from_beginning__(returnFlag);}
    int removeAt(int index,int returnFlag=0){return __remove_from_particular_index__(index, returnFlag);}
    int removeLast(int returnFlag=0){return __remove_from_end__(returnFlag);}

};

int main()
{
    LinkedList list;
    list.append(4);
    list.append(2);
    list.prepend(3);
    list.insert(2,99);
    cout<<list<<endl;
    cout<<list.removeAt(45,1)<<endl;
    cout<<list<<endl;
    return 0;
}