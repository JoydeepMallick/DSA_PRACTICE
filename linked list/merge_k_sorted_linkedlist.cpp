//read more about priority queues : https://www.baeldung.com/cs/priority-queue

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            priority_queue< pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> minpq;
            
            for(auto head : lists){
                if(head != nullptr) minpq.push({head->val, head});
            }
            ListNode *dummyHead = new ListNode(-1), *tmp = dummyHead;
            while(!minpq.empty()){
                //pop the highest priority element
                ListNode *curnode = minpq.top().second;
                minpq.pop();
                tmp->next = curnode;
                tmp = tmp->next;
                //push curnode's next into queue
                if(curnode->next != nullptr){
                    minpq.push({curnode->next->val, curnode->next});
                }
            }
            return dummyHead->next;
        }
    };