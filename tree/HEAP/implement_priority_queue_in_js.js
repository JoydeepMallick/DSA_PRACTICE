class PriorityQueue {
    constructor(comparator = (a, b) => a - b) {
        this.heap = [];
        this.compare = comparator;
    }

    push(val) {
        this.heap.push(val);
        this.heap.sort(this.compare); // Sorting ensures priority order
    }

    pop() {
        return this.heap.shift(); // Removes highest-priority element
    }

    peek() {
        return this.heap[0]; // Returns highest-priority element
    }

    size() {
        return this.heap.length; // Returns size
    }

    isEmpty() {
        return this.heap.length === 0;
    }
}

// Min-Heap (default)
let minPQ = new PriorityQueue();
minPQ.push(10);
minPQ.push(5);
minPQ.push(20);

console.log("Top Element:", minPQ.peek()); // 5
minPQ.pop();
console.log("New Top Element:", minPQ.peek()); // 10
console.log("Size:", minPQ.size()); // 2
