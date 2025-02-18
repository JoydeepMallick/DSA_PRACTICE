/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */

let reversetillstop = function(head, stop){
    let tmp = head, prevnode = null;
    while(tmp != stop){
        let nextnode = tmp.next;
        tmp.next = prevnode;
        prevnode = tmp;
        tmp = nextnode;
    }
    return prevnode;
}

var reverseKGroup = function(head, k) {
    let steps = 0;
    let stop = head;
    while(stop != null && steps < k){
        stop = stop.next;
        steps++;
    }
    
    if(steps < k) return head;

    let newhead = reversetillstop(head, stop);
    let tailofreversed = head;//post reversal new tail
    let nextstart = stop;//new starting point is the last stop point
    //connect new tail to new head but new head needs to be computed first so recursive call 
    tailofreversed.next = reverseKGroup(nextstart, k);

    return newhead;
};