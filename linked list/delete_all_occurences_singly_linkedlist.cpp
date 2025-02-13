/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} val
 * @return {ListNode}
 */
var removeElements = function(head, val) {
    let tmp = head, prevnode = null, nextnode = null;
    while(tmp != null){
     if(tmp.val === val){
         if(tmp === head){
             head = head.next;
             //prev remains null
         }
         nextnode = tmp.next;
         if(prevnode != null) prevnode.next = nextnode;
         tmp = nextnode;
     }else{
         prevnode = tmp;
         tmp = tmp.next;
     }
    } 
    return head;
 };