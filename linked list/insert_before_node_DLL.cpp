class Node{
    public:
    int data;
    Node *prev;
    Node *next;
    Node(int val, Node *prev, Node *next){
        data = val;
        this->prev = prev;
        this->next = next;
    }
};

void insertBeforeNode(Node* node, int val){
    Node *prevnode = node->prev;
    Node *newnode = new Node(val, prevnode, node);
    prevnode->next = newnode;
    node->prev = newnode;
}