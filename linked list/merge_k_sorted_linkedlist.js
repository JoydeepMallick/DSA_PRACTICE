/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */

let mergesortedLL = function(t1, t2){
    let dummyhead = new ListNode(-1);
    let tmp = dummyhead;
    while(t1 != null && t2 != null){
        if(t1.val < t2.val){
            tmp.next = t1;
            t1 = t1.next;
        }else{
            tmp.next = t2;
            t2 = t2.next;
        }
        tmp = tmp.next;
    }
    tmp.next = (t1 != null) ? t1 : t2;
    return dummyhead.next;
}

var mergeKLists = function(lists) {
    const n = lists.length;
    if(n == 0) return null;
    if(n == 1) return lists[0];
    let head1 = lists[0];
    for(let i = 1; i < n; i++){
        let head2 = lists[i];
        head1 = mergesortedLL(head1, head2);
    }
    return head1;
};