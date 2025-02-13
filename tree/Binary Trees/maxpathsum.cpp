#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    public:
        int recurfunc(TreeNode* root, int &maxsum){
            if(root == nullptr) return 0;
            //do not pick negatives from subtree if thats only the possible max rather pick 0
            int maxfromleftsubtree = max(0, recurfunc(root->left, maxsum));
            int maxfromrightsubtree = max(0, recurfunc(root->right, maxsum));
            //if current node is assumed highest node in path and serves as turning point for rest
            int curmaxpathsum = root->val + maxfromleftsubtree + maxfromrightsubtree;
            //check if maxsum is attend or not
            maxsum = max(maxsum, curmaxpathsum);
    
            //return the subtrees since we no more consider the node to be turning point so either one child with node value returned
            return root->val + max(maxfromleftsubtree, maxfromrightsubtree); 
        }
    
        int maxPathSum(TreeNode* root) {
            int maxsum = INT_MIN;
            recurfunc(root, maxsum);
            return maxsum;
        }
};