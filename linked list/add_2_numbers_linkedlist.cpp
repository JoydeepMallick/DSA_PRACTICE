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

Node *addTwoNumbers(Node *num1, Node *num2)
{
    Node* dummy = new Node(-1);
    Node* current = dummy, *l1 = num1, *l2 = num2;
    int carry = 0;
    
    while (l1 || l2 || carry) {
        int val1 = l1 ? l1->data : 0;
        int val2 = l2 ? l2->data : 0;
        
        int sum = val1 + val2 + carry;
        carry = sum / 10;
        
        current->next = new Node(sum % 10);
        current = current->next;
        
        l1 = l1 ? l1->next : nullptr;
        l2 = l2 ? l2->next : nullptr;
    }
    
    Node* result = dummy->next;
    delete dummy;  // Clean up the dummy node
    return result;
}
