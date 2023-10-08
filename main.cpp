#include<iostream>

using namespace std;


class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

int main()
{
    Node a = 4;
    cout<<a.data;
    return 0;
}