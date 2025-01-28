
class Node
{
public:
    int data;
    Node* next;
    Node(int data)
    { 
        this->data = data;
        next = NULL;
    }
};


Node* oddEvenList(Node* head)
{
    if(head==nullptr || head->next==nullptr) return head;
    Node *odd = head, *even = head->next, *evenHead = head->next;
    while(even != nullptr && even->next != nullptr){
            odd->next = odd->next->next;
            odd = odd->next;
      
            even->next =even->next->next;
            even = even->next;
        
    }
    odd->next = evenHead;
    return head;
}