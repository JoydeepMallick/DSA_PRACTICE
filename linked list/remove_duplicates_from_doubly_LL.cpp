/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/


 //brute 
 Node * removeDuplicates(Node *head)
 {
     if(head == nullptr || head->next == nullptr) return head;//no duplicates
 
     Node* tmp = head;
     unordered_map<int, bool> visited;
     while(tmp != nullptr){
         Node* prevnode = tmp->prev, *nextnode = tmp->next;
         if(visited[tmp->data]){
             if(prevnode != nullptr) prevnode->next = nextnode;
             if(nextnode != nullptr) nextnode->prev = prevnode;
             delete tmp;
         }
         else{
             visited[tmp->data] = true;
         }
         tmp = nextnode;
     }
     return head;
 }
 

 //optimal 1 but multiple connect disconnect
 Node * removeDuplicates(Node *head)
{
    if(head == nullptr || head->next == nullptr) return head;//no duplicates

    Node* tmp = head;
    //we know its sorted so all stay together
    while(tmp != nullptr){
        Node* prevnode = tmp->prev, *nextnode = tmp->next;
        if(prevnode != nullptr && prevnode->data == tmp->data){
            if(prevnode != nullptr) prevnode->next = nextnode;
            if(nextnode != nullptr) nextnode->prev = prevnode;
            delete tmp;
        }

        tmp = nextnode;
    }
    return head;
}


//optimal 2 disconnect connect only at unique elements
Node * removeDuplicates(Node *head)
{
    Node* tmp = head;
    while(tmp != nullptr && tmp->next != nullptr){//handles case of single and no element
        Node *nextnode = tmp->next;
        while(nextnode != nullptr && tmp->data == nextnode->data){
            //update nextnode since its duplicate
            Node *duplicate = nextnode;
            nextnode = nextnode->next;
            delete duplicate;
        }
        // current tmp point to next unique element
        tmp->next = nextnode;
        if(nextnode != nullptr) nextnode->prev = tmp;

        //update current pointer
        tmp = nextnode;
    }
    return head;
}
