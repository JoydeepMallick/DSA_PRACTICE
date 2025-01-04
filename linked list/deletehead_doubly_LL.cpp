
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node() : data(0), next(nullptr), prev(nullptr) {}
    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
    Node(int x, Node* next, Node* prev) : data(x), next(next), prev(prev) {}
};

Node * deleteHead(Node *head) {
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    Node* tmp = head;
    head = head->next;
    head->prev = nullptr;
    tmp->next = nullptr;
    delete tmp;
    
    return head;
}