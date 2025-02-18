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
var rotateRight = function(head, k) {    
    //find length of linkedlist
    let tmp = head, oldtail = null;
    let n = 0;
    while(tmp != null){
        oldtail = tmp;
        tmp = tmp.next;
        n++;
    }

    //find reduced k
    k = k%n;
    if(k == 0 || head == null) return head;


    //find node where the newhead lies
    let splitat = n-k, cnt = 0;
    let newhead = null, newtail = head;
    while(newtail != null){
        cnt++;
        if(cnt == splitat) break;
        newtail = newtail.next;
    }
    newhead = newtail.next;
    if(newtail != null) newtail.next = null;
    if(oldtail != null) oldtail.next = head;
    return newhead;
};