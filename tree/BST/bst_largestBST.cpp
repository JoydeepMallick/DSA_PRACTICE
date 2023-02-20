#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        //constructor for TreeNode creation
        TreeNode(int data){
            this->val = data;
            this->left = NULL;
            this->right = NULL;
        }
};

/*
 * define a new class to store 3 data together for use later
 * maxNode --> it stores min valued node in right subtree
 * minNode --> it stores max valued node in left subtree
 * maxSize --> means the total number of nodes in a particular BST node
 */
class NodeValue{
    public:
        int maxNode, minNode, maxSize;

        NodeValue(int minNode, int maxNode, int maxSize){
            this->maxNode = maxNode;
            this->minNode = minNode;
            this->maxSize = maxSize;
        }
};

class Solution{
    private:
        NodeValue largestBSTSubtreeHelper(TreeNode* root){
            //an empty node of a BST of size 0
            if(!root) return NodeValue(INT_MAX, INT_MIN, 0);//for null values
            //we perform a preorder traversal inorder to move from bottom from both sides till top to valid each node
            auto leftSubtree = largestBSTSubtreeHelper(root->left);
            auto rightSubtree = largestBSTSubtreeHelper(root->right);

            //current node is greater than max node in left subtree and smaller than smallest node in right subtree
            if(leftSubtree.maxNode < root->val &&  root->val < rightSubtree.minNode){
                /* surely the node is a BST */
                return NodeValue( min(root->val, leftSubtree.minNode), max(rightSubtree.maxNode, root->val), leftSubtree.maxSize + rightSubtree.maxSize + 1 );

                /* we return the min of root val and max node of left subtree for 'max of left subtree of root' and similarly return the max of root value and min node of right subtree as 'root right min value'. */
            }
/* otherwise return [-inf, inf] so that parent aint a valid BST */
            return NodeValue(INT_MIN, INT_MAX, max(leftSubtree.maxSize, rightSubtree.maxSize));
        }

    public:
        int largestBSTSubtree(TreeNode* root){
            return largestBSTSubtreeHelper(root).maxSize;
        }
};

int main(){
/*
                   7
                 /   \
                3     10
               / \    /
              2   6  11
             /   /  /
            1   5  8
               /
              4

              only node tree is prefect BST hence output must be 6.
     */
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(5);
    root->left->right->left->left = new TreeNode(4);
    root->right = new TreeNode(10);
    root->right->left = new TreeNode(11);
    root->right->left->left = new TreeNode(8);
    
    Solution sl;
    int sz = sl.largestBSTSubtree(root);
    cout << "Size of largest valid subtree in root : " << sz << endl;
    return 0;
}
