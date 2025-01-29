

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



Node* reverse(Node *head)
{
    if (head == nullptr || head->next == nullptr) return head; // Base case: return the new head
    
    Node* newhead = reverse(head->next); // Recur for the rest of the list
    Node* nextnode = head->next;
    nextnode->next = head; // Reverse the link
    head->next = nullptr;
    return newhead;
}

bool isPalindrome(Node *head)
{
    //find middle element
    Node *fast = head, *slow = head;
    while(fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    //reverse 2nd half
    Node *secondhalf = reverse(slow->next);
    Node *reversedhead = secondhalf;
    Node *firsthalf = head;
    //check for palindrome
    while(secondhalf != nullptr){
        if(firsthalf->data != secondhalf->data){
            //bring the linkedlist to actual state
            reverse(reversedhead);
            return false;
        }
        firsthalf = firsthalf->next;
        secondhalf = secondhalf->next;
    }
    //bring the linkedlist to actual state
    reverse(reversedhead);
    return true;

}