// Definition of linked list node:
class Node {
    constructor(data = 0, next = null) {
        this.data = data;
        this.next = next;
    }
}

function addTwoNumbers(num1, num2) {
    let dummy = new Node(-1);
    let cur = dummy;
    let t1 = num1, t2 = num2;
    let carry = 0;
    while (t1 !== null || t2 !== null) {
        let val1 = t1 !== null ? t1.data : 0;
        let val2 = t2 !== null ? t2.data : 0;
        let sum = val1 + val2 + carry;
        let unitval = sum % 10;
        carry = Math.floor(sum / 10);
        let newNode = new Node(unitval);
        cur.next = newNode;
        cur = cur.next;
        if (t1 !== null) t1 = t1.next;
        if (t2 !== null) t2 = t2.next;
    }
    if (carry !== 0) {
        cur.next = new Node(carry);
    }
    let newhead = dummy.next;
    //deletion of unused handle by GC
    return newhead;
}

module.exports.addTwoNumbers = addTwoNumbers;
