/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/



class Solution {
    public:
        void insertCopyInBetween(Node* head){
            Node* tmp = head;
            while(tmp != nullptr){
                Node *copynode = new Node(tmp->val);
                Node *nextnode = tmp->next;
                tmp->next = copynode;
                copynode->next = nextnode;
    
                tmp = nextnode;
            }
        }
    
        void connectRandomPointers(Node* head){
            Node *tmp = head;
            while(tmp != nullptr){
                Node *copynode = tmp->next;
                Node *randomcopynode = (tmp->random != nullptr) ? tmp->random->next : nullptr;// tmp.random is the actual node but we need to connect to copy random node thats the next one
                copynode->random = randomcopynode;
                tmp = tmp->next->next;  
            }
        }
    
        Node* DeepCopyList(Node *head){
            Node *tmp = head;
            Node *dummyHead = new Node(-1), *tmp2 = dummyHead;
            while(tmp != nullptr){  
                //seperating the nodes to 2 linkedlist
                tmp2->next = tmp->next;
                tmp->next = tmp->next->next;
                //updating the pointers for next iteration
                tmp2 = tmp2->next;
                tmp = tmp->next;
            }
            return dummyHead->next;
        }
    
        Node* copyRandomList(Node* head) {
            insertCopyInBetween(head);
            connectRandomPointers(head);
            return DeepCopyList(head);
        }
    };