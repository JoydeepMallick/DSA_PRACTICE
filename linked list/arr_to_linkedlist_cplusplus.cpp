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

Node* constructLL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* tmp = new Node(arr[i]);
        mover->next = tmp;
        mover = tmp;
    }
    return head;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = constructLL(arr);
    cout << head->data << endl;
    return 0;
}