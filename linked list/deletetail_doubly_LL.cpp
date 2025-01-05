
// Definition of doubly linked list:
struct Node {
    int data;
    Node *prev;
    Node *next;
    Node() : data(0), prev(nullptr), next(nullptr) {}
    Node(int val) : data(val), prev(nullptr, next(nullptr) {}
    Node(int val, Node *p, Node *n) : data(val), prev(p), next(n) {}
};

Node* deleteLastNode(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    Node* tail = head;
    // Stop at last
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    Node* newtail = tail->prev;
    newtail->next = nullptr;
    tail->prev = nullptr;
    delete tail;
    return head;
}
