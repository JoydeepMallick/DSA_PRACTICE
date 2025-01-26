

class Node
{
public:
    int data;
    Node *next,*prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev= NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
        this->prev= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};



Node* reverseDLL(Node* head)
{   
    //no or 1 element
    if(head == nullptr || head->next == nullptr) return head;
    Node *cur = head, *prevnode = nullptr;
    while(cur != nullptr){
        prevnode = cur->prev;
        cur->prev = cur->next;
        cur->next = prevnode;
        cur = cur->prev;
    } 
    head = prevnode->prev;
    return head;
}

