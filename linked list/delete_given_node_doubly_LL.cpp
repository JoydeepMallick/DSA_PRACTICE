/************************************************************

    Following is the linkedList class structure:

    class Node {
    public:
        int data;
        Node *next;
        Node *prev;

        Node(int val) {
            this->data = val;
            next = NULL;
            prev = NULL;
        }
    };

************************************************************/

void deleteNode(Node* node) {
    Node *nextnode = node->next, *prevnode = node->prev;
    // prevnode is never null
    if(nextnode == nullptr){
        prevnode->next = nullptr;
        node->prev = nullptr;
        delete(node);
        return;
    }
    prevnode->next = nextnode;
    nextnode->prev = prevnode;
    node->prev = node->next = nullptr;
    delete(node);
}