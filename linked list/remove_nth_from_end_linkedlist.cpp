// good concept of slow and fast pointer : https://medium.com/@arifimran5/fast-and-slow-pointer-pattern-in-linked-list-43647869ac99



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


Node* removeKthNode(Node* head, int K)
{
    Node *fast = head, *slow = head;
    for(int i = 1; i <= K; i++) fast = fast->next;
    if(fast == nullptr){
        //k is equal to length of linked list
        Node *todel = head;
        head = head->next;
        delete todel;
        return head;
    }
    while(fast->next != nullptr){
        slow = slow->next;
        fast = fast->next;
    }
    Node *todel = slow->next;
    slow->next = todel->next;
    delete todel;
    return head;
}
