#include<iostream>
using namespace std;

class Node {
    public:
    
    int data;
    Node *prev, *next;
    
    Node(int val){
        data = val;
        prev = next = nullptr;
    }
    Node(int val, Node *prev1, Node *next1){
        data = val;
        prev = prev1;
        next = next1;
    }
};

Node *insertBeforeTail(Node *head, int val){

    if(head == nullptr){
        return new Node(val);
    }
    Node *tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }
    Node *newNode = new Node(val, tail->prev, tail);
    tail->prev->next = newNode;
    tail->prev = newNode;
    return head;
}