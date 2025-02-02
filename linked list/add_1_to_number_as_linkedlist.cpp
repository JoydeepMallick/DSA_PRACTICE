/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/


//brute
Node* reverse(Node* head){
    Node* tmp = head, *prevnode = nullptr;
    while(tmp != nullptr){
        Node* nextnode = tmp->next;
        tmp->next = prevnode;
        prevnode = tmp;
        tmp = nextnode;
    }
    return prevnode;
}


Node *addOne(Node *head)
{
    //reverse LL
    Node* newhead = reverse(head);
    int carry = 1;
    Node* tmp = newhead;
    while(tmp != nullptr){
        if(carry == 0) break;
        int sum = tmp->data + carry;
        carry = sum/10;
        int nodevalue = sum%10;
        tmp->data = nodevalue;
        tmp = tmp->next;
    }
    //reverse again
    newhead = reverse(newhead);
    if(carry != 0){
        return new Node(carry, newhead);
    }else{
        return newhead;
    }
}


//optimal using recursion

int recur(Node* head){
    if(head == nullptr) return 1;
    else{
        int sum = head->data + recur(head->next);
        int carry = sum/10;
        int nodeval = sum%10;
        head->data = nodeval;
        return carry;
    }
}


Node *addOne(Node *head)
{
    int carry = recur(head);
    if(carry != 0){
        head = new Node(carry, head);
    }
    return head;
}   
