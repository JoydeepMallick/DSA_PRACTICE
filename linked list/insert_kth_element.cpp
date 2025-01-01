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

Node* insertatkth(Node* head, int ele, int k){
    if(head == NULL){
        if(k == 1){
            return new Node(ele);
        }
        else return NULL;
    }
    if(k == 1){
        Node* tmp = new Node(ele, head);
        return tmp;
    }
    int cnt = 0;
    Node* tmp = head;
    while(tmp != NULL){
        cnt++;
        if(cnt == (k-1)){
            Node *newele = new Node(ele, tmp->next);
            tmp->next = newele;
            break;
        }
    }
    return head;
}