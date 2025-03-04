/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */



 //concept of merge sort
class Solution {
    public:
        ListNode* findmiddle(ListNode *head){
            ListNode* fast = head->next, *slow = head;
            while(fast != nullptr && fast->next != nullptr){
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }
    
        ListNode* mergetwoLL(ListNode *lefthead, ListNode *righthead){
            //here we merge 2 sorted linkedlist
            ListNode *dummyHead = new ListNode(-1), *tmp = dummyHead;
            while(lefthead != nullptr && righthead != nullptr){
                if(lefthead->val < righthead->val){
                    tmp->next = lefthead;
                    lefthead = lefthead->next;
                }else{
                    tmp->next = righthead;
                    righthead = righthead->next;
                }
                tmp = tmp->next;
            }
    
            if(lefthead != nullptr){
                tmp->next = lefthead;
            }
            if(righthead != nullptr){
                tmp->next = righthead;
            }
            return dummyHead->next;
        }
    
        ListNode* mergesortLL(ListNode *head){
            if(head == nullptr || head->next == nullptr) return head; // 1 or no element
            ListNode *middleNode = findmiddle(head);
            ListNode *lefthead = head, *righthead = middleNode->next;
            middleNode->next = nullptr; //important else in merge function leftnode will go on traversing entire list which is not desired and cause error
    
            //we know  a single node is sorted in itself
            ListNode *newlefthead = mergesortLL(lefthead);
            ListNode *newrighthead = mergesortLL(righthead);
    
            return mergetwoLL(newlefthead, newrighthead);
        }
    
    
        ListNode* sortList(ListNode* head) {
            return mergesortLL(head);
        }
    };