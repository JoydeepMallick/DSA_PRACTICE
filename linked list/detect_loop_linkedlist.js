/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {boolean}
 */

//brute
var hasCycle = function(head) {
    let tmp = head;
    let mapnodes = new Map();
    while(tmp != null){
        if(mapnodes.has(tmp)) return true;
        mapnodes.set(tmp, true);
        tmp = tmp.next;
    }
    return false;

};