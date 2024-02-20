#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

Node* newNode(int key){
    //no space allocation needed in case of objects in c++
    //its already happens within
    Node* node = new Node();
    node->data = key;
    node->next = NULL;
    return node;
}

void insert(Node* &root, int key){
    Node* tmp = root;
    if(root == NULL) root = newNode(key);
    else{
        while(tmp->next) tmp = tmp->next;
        tmp->next = newNode(key);
    }
}

void traverse(Node* root){
    while(root){
        cout << root->data << " ";
        root = root->next;
    }
    cout << endl;
}

/* Node* reverse(Node* head){ */
/* if(head==NULL || head->next==NULL) return head;//if 0 or 1 node */
/* Node *prev, *cur, *next; */
/* cur = head; */
/* prev = NULL; */
/* next = cur; */
/* while(next!=NULL || cur){ */
/* next = cur->next; */
/* cur->next = prev; */
/* prev = cur; */
/* cur = next; */
/* } */
/* head = prev; */
/* return head; */
/* } */

Node* reverse(Node* head){
    Node *nextNode, *prevNode = NULL;
    while (head) {
        nextNode = head->next;
        head->next = prevNode;
        prevNode = head;
        head = nextNode;
    }
    return prevNode;
}

/*
   ListNode* reverseList(ListNode *head, ListNode *nextNode = NULL, ListNode *prevNode = NULL) {
        return head ? reverseList(head->next, (head->next = prevNode, nextNode), head) : prevNode;
    }
 */

int main(){
    Node* root = NULL;
    insert(root, 23);
    insert(root, 12);
    insert(root, 67);
    insert(root, 45);
    cout << "Traverse root : ";
    traverse(root);
    root = reverse(root);
    cout << "\nAfter reversal root traversal : ";
    traverse(root);
    return 0;
}
