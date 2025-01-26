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

Node *insertBeforekthNode(Node *head, int val, int k){
    if(head == nullptr){
        if(k==1) return new Node(val);
        else return nullptr;
    }
    if(k == 1){
        Node *newNode = new Node(val, nullptr, head);
        head->prev = newNode;
        return newNode;
    }
    //find kth node
    Node *kthnode = head;
    bool found = false;
    int cnt = 0;
    while(kthnode->next != nullptr){
        cnt++;
        if(cnt == k) {
            found = true;
            break;
        }
        kthnode = kthnode->next;
    }
    if(!found) return head;//k is invalid
    
    Node *newNode = new Node(val, kthnode->prev, kthnode);
    kthnode->prev->next = newNode;
    kthnode->prev = newNode;
    return head;
}