#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node* next) : data(x), next(next) {}
};

Node* insertbeforeval(Node* head, int ele, int val){
    if(head == NULL){
        return NULL;
    }
    if(head->data == val){
        Node* tmp = new Node(ele, head);
        return tmp;
    }
    Node* tmp = head;
    while(tmp != NULL){
        if(tmp->next->data == val){
            Node *newele = new Node(ele, tmp->next);
            tmp->next = newele;
            break;
        }
    }
    return head;
}   