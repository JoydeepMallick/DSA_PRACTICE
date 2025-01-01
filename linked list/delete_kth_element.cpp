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

Node* deletekth(Node* head, int k) {
    if (head == NULL) return NULL;
    if (k == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    int elecnt = 0;
    while(temp != NULL){
        elecnt++;
        if(elecnt == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    delete temp1;
    return head;
}