//this is the accurate code which will work in online assessments and judges with edge cases

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
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>> lvlorder;
            if(root == nullptr) return lvlorder;//empty vector returned, check is needed if tree is empty to avoid nullptr exception
            
            queue<TreeNode*> q;
            
            q.push(root);
            while(!q.empty()){
                //compute no. elements in each level
                int size = q.size();
                vector<int> tmparr;
                while(size > 0){
                    TreeNode *node = q.front();
                    q.pop();//void function
                    size--;
                    tmparr.push_back(node->val);
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
                lvlorder.push_back(tmparr);
            }
            return lvlorder;
        }
    };