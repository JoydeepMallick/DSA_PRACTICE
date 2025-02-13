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
class Solution {
    public:
        ListNode* reverse(ListNode* head){
            if(head == nullptr || head->next == nullptr) return head;
            ListNode* prevnode = nullptr, *tmp = head;
            while(tmp != nullptr){
                ListNode *nextnode = tmp->next;
                tmp->next = prevnode;
                prevnode = tmp;
                tmp = nextnode;
            }
            return prevnode;
        }
    
        int pairSum(ListNode* head) {
            ListNode* fast = head, *slow = head;
            while(fast != nullptr){//always even length
                slow = slow->next;
                fast = fast->next->next;
            }
            ListNode* firsthalf = head, *secondhalf = slow;
            secondhalf = reverse(secondhalf);
            ListNode *reversedhead = secondhalf;
            int maxsum = INT_MIN;
            while(firsthalf != slow){
                int sum = firsthalf->val + secondhalf->val;
                maxsum = max(maxsum, sum);
                firsthalf = firsthalf->next;
                secondhalf = secondhalf->next;
            }
            //correct the distortion caused
            reverse(reversedhead);
    
            return maxsum;
        }
    };