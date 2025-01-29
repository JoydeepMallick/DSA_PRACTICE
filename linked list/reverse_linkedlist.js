/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function(head) {
    if(head === null || head.next === null) return head;
    let cur = head;
    let prevnode = null;
    while(cur != null){
        let tmp = cur.next;
        cur.next = prevnode;
        prevnode = cur;
        cur = tmp;
    }
    return prevnode;
};