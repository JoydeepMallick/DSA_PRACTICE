/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function(headA, headB) {
    let mapnodes = new Map();
    let tmp = headA;
    while(tmp != null){
        mapnodes.set(tmp, true);
        tmp = tmp.next;
    }
    tmp = headB;
    while(tmp != null){
         if(mapnodes.has(tmp)) return tmp;
        tmp = tmp.next;
    }
    return null;
};

// Time : O(N+M)
// Space : O(N)