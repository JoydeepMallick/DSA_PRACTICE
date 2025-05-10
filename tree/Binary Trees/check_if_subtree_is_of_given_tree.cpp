/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    //compare both as if they were similar with roots as starting point
    bool isSame(TreeNode* root1, TreeNode* root2){
        //since both roots end together no mismatch 
        //subtree found
        if(root2 == nullptr && root1 == nullptr) return true;
        if(root2 == nullptr || root1 == nullptr) return false;//root1 ended or root2 ended meaning subtree not match
        if(root1->val != root2->val) return false;
        return isSame(root1->left, root2->left) && isSame(root1->right, root2->right);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr) return false;//nothing to compare
        if(isSame(root, subRoot)) return true;//both trees exactly the same
        //since both are not exactly similar we need to check for all possiblities of starting point in root

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};