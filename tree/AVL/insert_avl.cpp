#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node *left, *right;
        int height;//stores height of current node as its required in future calcualtions of order
};

int height(Node* nd){
    if(nd==NULL) return 0;
    else return nd->height;
}

Node* newNode(int key){
    Node* node = new Node();//new object of type Node*
    node->val = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;//remember new node is initially added at leaf following rules of BST Insertion
    return(node);
}
/*
    y       Anticlockwise            x
    / \     Right Rotation          /  \
   x   T3   - - - - - - - >        T1   y 
  / \       < - - - - - - -            / \
 T1  T2     Left Rotation             T2  T3
            Clockwise
*/

/* above example shows how clockwise and anticlockwise rotations i.e. LL and RR occur respectively. */

/*
1. Left Left Case 

T1, T2, T3 and T4 are subtrees.
         z                                      y 
        / \                                   /   \
       y   T4      Right Rotate (z)          x      z
      / \          - - - - - - - - ->      /  \    /  \ 
     x   T3                               T1  T2  T3  T4
    / \
  T1   T2


2. Left Right Case 

     z                               z                           x
    / \                            /   \                        /  \ 
   y   T4  Left Rotate (y)        x    T4  Right Rotate(z)    y      z
  / \      - - - - - - - - ->    /  \      - - - - - - - ->  / \    / \
T1   x                          y    T3                    T1  T2 T3  T4
    / \                        / \
  T2   T3                    T1   T2


3. Right Right Case 

  z                                y
 /  \                            /   \ 
T1   y     Left Rotate(z)       z      x
    /  \   - - - - - - - ->    / \    / \
   T2   x                     T1  T2 T3  T4
       / \
     T3  T4


4. Right Left Case 

   z                            z                            x
  / \                          / \                          /  \ 
T1   y   Right Rotate (y)    T1   x      Left Rotate(z)   z      y
    / \  - - - - - - - - ->     /  \   - - - - - - - ->  / \    / \
   x   T4                      T2   y                  T1  T2  T3  T4
  / \                              /  \
T2   T3                           T3   T4

*/

Node* clockwiseRotate(Node* node){
    /*
     *      ___>>
     *     / 
     *    /  clockwise
     *    |
     *     \
     *      \___
     *
     * x -> current node
     * y -> right child of current node, becomes future parentnode
     * T2 -> leftchild of future parentnode, gets disconnected hence loose node on rotation
     
    we can rest assume that left child of current node and right child of future parent node are untouched

            x         y
             \       /
              y ==> x
             /       \
            T1        T1
*/
    Node* parentnode = node->right;
    Node* loosenode = parentnode->left;
    //perform rotation meaning parentnode becomes topmost node in given subtree and current node is attached to left of it
    parentnode->left = node;
    node->right = loosenode;//attach the once left child loosenode of that parentnode to currentnode
    //update heights of current nodes post rotation
    parentnode->height = max(height(parentnode->left), height(parentnode->right)) + 1;
    node->height = max(height(node->left), height(node->right)) + 1;
        
    return parentnode;
}

Node* anticlockwiseRotate(Node* node){
    /*
     * Here we are least concerned of the right child of currrent node and the left child of the right child of current node as they are untouched...
     *
     * y -> current node
     * x -> left child of current node, becomes the parent in future
     * T2 -> rightchild of left child of current node, gets disconnected hence loose node on rotation
            y       x
           /         \
          x   ==>     y
           \         /
           t2        t2
                
     */
    Node* parentnode = node->left;
    Node* loosenode = parentnode->right;
    //perform rotation meaning parentnode becomes topmost node in given subtree and current node is attached to right of it
    parentnode->right = node;
    node->left = loosenode;//attach the once right child loosenode of that parentnode to currentnode
    //update heights of current nodes post rotation
    parentnode->height = max(height(parentnode->left), height(parentnode->right)) + 1;
    node->height = max(height(node->left), height(node->right)) + 1;

    return parentnode;
}

int BalanceFactor(Node* node){
    if(node == NULL ) return 0;
    else return height(node->left) - height(node->right);
}

Node* insert(Node* root, int key){
    //simple bst insertion with added cases for balancing
    if(root == NULL) return newNode(key);//no node at current location hence insert this new node as leaf
    if(key < root->val) root->left = insert(root->left, key);
    else if(key > root->val) root->right = insert(root->right, key);
    /*
       else return node;//avoid equal keys
     */


    root->height = 1 + max(height(root->left), height(root->right) );//update height of current root after insertion of root has been competed
    int bfactor = BalanceFactor(root);//check if the current node is unbalnced
    /*
Note: here we seen that as stack piles up in recursive fashion we actually go on calculating balance factor in reverse fashion from inserted node up till the main root of tree hence whenever we hit a balance factor other than -1,0,1 we immediately respond to one of the rotations

Its like doing everything in bottom to up fashion
     */
    
    // Left Left Case
    if (bfactor > 1 && key < root->left->val)
        return anticlockwiseRotate(root);
 
    // Right Right Case
    if (bfactor < -1 && key > root->right->val)
        return clockwiseRotate(root);
 
    // Left Right Case
    if (bfactor > 1 && key > root->left->val){
        root->left = clockwiseRotate(root->left);
        return anticlockwiseRotate(root);
    }
 
    // Right Left Case
    if (bfactor < -1 && key < root->right->val){
        root->right = anticlockwiseRotate(root->right);
        return clockwiseRotate(root);
    }
    // return the current node after modifications 
    return root;
}

void preOrder(Node *root){
    if(root != NULL){
        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main(){
    Node *root = NULL;
    while(1){
        cout << "\n\n0. Exit\n1. Insert\n Choice : ";
        int ch;
        cin >> ch;
        if(ch==0) break;
        else if(ch==1){
            cout << "Enter element : ";
            cin >> ch;
            root = insert(root, ch);
            cout << "Inorder after insertion : ";
            inorder(root);
            cout << "\nPreorder after insertion : ";
            preOrder(root);
        }
        else cout << "Wrong choice!\n\n";
    }
    return 0;
}
