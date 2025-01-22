class Node {
public:
    int val;
    Node *next;
    Node *prev;
    Node() : val(0), next(nullptr), prev(nullptr) {}
    Node(int x) : val(x), next(nullptr), prev(nullptr) {}
    Node(int x, Node *next, Node *prev) : val(x), next(next), prev(prev) {}
};

Node* deleteHead(Node* head){
    if(head == nullptr) return nullptr;
    if(head->next == nullptr){
        delete(head);
        return nullptr;
    }
    Node* tmp = head;
    head = head->next;
    head->prev = nullptr;
    delete(tmp);
    return head;
}

Node* deleteTail(Node* head){
    if(head == nullptr) return nullptr;
    if(head->next == nullptr){
        delete(head);
        return nullptr;
    }
    Node* tmp = head;
    while(tmp->next != nullptr){
        tmp = tmp->next;
    }
    Node* newtail = tmp->prev;
    newtail->next = nullptr;
    tmp->prev = nullptr;
    delete(tmp);
    return head;
}

Node *deleteNode(Node *head, int k){
    if(head == nullptr) return nullptr;
    Node* tmp = head;
    int cnt = 0;
    while(tmp != nullptr){
        cnt++;
        if(cnt == k) break;
        tmp = tmp->next;
    }
    Node* prevnode = tmp->prev;
    Node* nextnode = tmp->next;
    if(prevnode == nullptr && nextnode == nullptr) return nullptr;
    else if(prevnode == nullptr) return deleteHead(head);
    else if(nextnode == nullptr) return deleteTail(head);

    prevnode->next = nextnode;
    nextnode->prev = prevnode;
    tmp->prev = nullptr;
    tmp->next = nullptr;
    delete(tmp);
    return head;
}