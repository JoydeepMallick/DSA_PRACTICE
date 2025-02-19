/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
var mergeTwoLists = function(list1, list2) {
    let t1 = list1, t2 = list2;
    let dummyHead = new ListNode(-1);
    let tmp = dummyHead;
    while(t1 != null && t2 != null){
        if(t1.val < t2.val){
            tmp.next = t1;
            tmp = t1;
            t1 = t1.next;
        }else{
            tmp.next = t2;
            tmp = t2;
            t2 = t2.next;
        }
    }
    if(t1 != null) tmp.next = t1;
    if(t2 != null) tmp.next = t2;

    let newhead = dummyHead.next;
    return newhead;
};