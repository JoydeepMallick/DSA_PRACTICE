/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {boolean}
 */


var isPalindrome = function(head) {
    //find middle element
    let fast = head, slow = head;
    while(fast.next !== null && fast.next.next !== null){
        slow = slow.next;
        fast = fast.next.next;
    }
    //reverse 2nd half
    let secondhalf = reverse(slow.next);
    let reversedhead = secondhalf;
    let firsthalf = head;
    //check for palindrome
    while(secondhalf !== null){
        if(firsthalf.val !== secondhalf.val){
            //bring the linkedlist to actual state
            reverse(reversedhead);
            return false;
        }
        firsthalf = firsthalf.next;
        secondhalf = secondhalf.next;
    }
    //bring the linkedlist to actual state
    reverse(reversedhead);
    return true;
};

function reverse(head)
{
    if (head === null || head.next === null) return head; // Base case: return the new head
    
    let newhead = reverse(head.next); // Recur for the rest of the list
    let nextnode = head.next;
    nextnode.next = head; // Reverse the link
    head.next = null;
    return newhead;
}

