#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    
    Node(int val) : key(val), left(nullptr), right(nullptr) {}
};

class PriorityQueueBST {
private:
    Node* root;

    // Insert a new node into the BST (its the same irrespective of min-priortiy queue or max-priority queue) unlike heaps where different kind of heaps are used for min and max priority queues
    Node* insert(Node* node, int key) {
        if (!node) return new Node(key);
        if (key < node->key)
            node->left = insert(node->left, key);
        else
            node->right = insert(node->right, key);
        return node;
    }


    /*--------------------- Below Implementation are of min-priority queue ---------------------*/ 
    // Find the minimum node (smallest element)
    Node* findMin(Node* node) {
        while (node->left) node = node->left;
        return node;
    }

    // Delete the minimum node (root of min-priority queue)
    Node* deleteMin(Node* node) {
        if (!node) return nullptr;
        if (!node->left) {
            Node* rightSubTree = node->right;
            delete node;
            return rightSubTree;
        }
        node->left = deleteMin(node->left);
        return node;
    }

      /*--------------------- Below Implementation are of max-priority queue ---------------------*/ 
    Node* findMax(Node* node) {
        while (node->right) node = node->right;
        return node;
    }
    
    Node* deleteMax(Node* node) {
        if (!node) return nullptr;
        if (!node->right) {
            Node* leftSubTree = node->left;
            delete node;
            return leftSubTree;
        }
        node->right = deleteMin(node->right);
        return node;
    }

public:
    PriorityQueueBST() : root(nullptr) {}

    // Insert an element
    void push(int key) {
        root = insert(root, key);
    }

    // Get the minimum element (Peek) for min priority queue, for max priority queue we will get the maximum element
    int top() {
        if (!root) throw runtime_error("Priority Queue is empty!");
        return findMin(root)->key;
    }

    // Remove the minimum element (Pop) for min priority queue, for max priority queue we will remove the maximum element
    void pop() {
        if (!root) throw runtime_error("Priority Queue is empty!");
        root = deleteMin(root);
    }

    // Check if empty
    bool empty() {
        return root == nullptr;
    }
};

int main() {
    PriorityQueueBST pq;
    pq.push(10);
    pq.push(5);
    pq.push(15);
    pq.push(3);
    pq.push(7);

    /*Irrespective of type of priority queue the BST will look like
        10
       /  \
     5     15
    /  \   
   3   7 

    */

    cout << "Top Element: " << pq.top() << endl; // Should print 3
    pq.pop();
    cout << "Top Element after pop: " << pq.top() << endl; // Should print 5

    return 0;
}
