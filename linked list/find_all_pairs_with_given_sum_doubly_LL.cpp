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
 *          this -> data = data;
 *          this -> prev = prev;
 *          this -> next = next;
 *      }
 * };
 *
 *************************************************************************/

 vector<pair<int, int>> findPairs(Node* head, int k)
 {
     vector<pair<int, int>> pairs;
     if(head == nullptr) return pairs;
     
     Node* left = head, *right = head;
     while(right->next != nullptr) right = right->next;
     while(left->data < right->data){
         int sum = left->data + right->data;
         if(sum > k){
             right = right->prev;
         }else if(sum < k){
             left = left->next;
         }else{
             pairs.push_back({left->data, right->data});
             left = left->next;
             right = right->prev;
         }
     }
     return pairs;
 }
 