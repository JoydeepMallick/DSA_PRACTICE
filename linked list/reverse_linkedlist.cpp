


class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

//loop based solution
Node* reverseLinkedList(Node *head)
{
    Node *cur = head, *prevnode = nullptr;
    while(cur != nullptr){
        Node *nextnode = cur->next;
        cur->next = prevnode;
        prevnode = cur;
        cur = nextnode;
    }
    return prevnode;
}

//recursive code 1
Node* recur(Node* cur, Node* prevnode){
   if (cur == nullptr) return prevnode;  // Base case: return the new head
    
    Node* nextnode = cur->next;  // Store next node
    cur->next = prevnode;        // Reverse the link

    return recur(nextnode, cur); // Move to the next node

}

Node* reverseLinkedList(Node *head)
{
    Node *cur = head, *prevnode = nullptr;

    return recur(cur, prevnode);
}


//recursive code 2
Node* reverseLinkedList(Node *head)
{
    if (head == nullptr || head->next == nullptr) return head; // Base case: return the new head
    
    Node* newhead = reverseLinkedList(head->next); // Recur for the rest of the list
    head->next->next = head; // Reverse the link
    head->next = nullptr;
    return newhead;
}