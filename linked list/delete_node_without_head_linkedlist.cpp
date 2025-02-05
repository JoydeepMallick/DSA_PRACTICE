/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
                // Overwrite data of next node on current node.
        node->val = node->next->val;
        ListNode* delnode = node->next;
        // Make current node point to next of next node.
        node->next = node->next->next;
        delete delnode;
    }
};