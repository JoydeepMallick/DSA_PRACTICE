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

void inorder(TreeNode* root){
    if(root==NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

TreeNode* invert(TreeNode* root){
    if(root==NULL) return NULL;
    TreeNode* newleft,*newright;
    newleft = invert(root->right);
    newright = invert(root->left);
    root->left = newleft;
    root->right = newright;
    return root;}

int main(){
    /*
                   7
                 /   \
                3     10
               / \    /
              2   6  9
             /   /  /
            1   5  8
               /
              4
     */
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(5);
    root->left->right->left->left = new TreeNode(4);
    root->right = new TreeNode(10);
    root->right->left = new TreeNode(9);
    root->right->left->left = new TreeNode(8);
    cout << "Inorder : ";
    inorder(root);
    root = invert(root);
    cout << "\nInorder post inversion : ";
    inorder(root);

    return 0;
}
