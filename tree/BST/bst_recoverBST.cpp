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

class Recover{
    private:
        TreeNode *first, *prev, *mid, *last;

        void inorder(TreeNode* root){
            if(root == NULL) return;
            inorder(root->left);

            if(prev!=NULL && (root->val < prev->val)){
                //avoiding first element of inorder for prev
                if(first == NULL){
                    first = prev;
                    mid = root;
                }
                else last = root;
            }
            //update prev
            prev = root;
            inorder(root->right);
        }

    public:
        void recoverTree(TreeNode* root){
            first = mid = last = NULL;
            prev = new TreeNode(INT_MIN);
            inorder(root);
            //if 2 nodes found to swap
            if(first && last) swap(first->val, last->val);
            //else if incorrect node found swap with its adjacent
            else if(first && mid) swap(first->val, mid->val);
        }
};

void InorderTraversal(TreeNode* root){
    if(root==NULL) return;
    InorderTraversal(root->left);
    cout << root->val << " ";
    InorderTraversal(root->right);
}

int main(){
    /*
     Before recovery :-

                   7
                 /   \
                3     10
               / \    /
              2   8  9
             /   /  /
            1   5  6
               /
              4
  After recovery :-

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
    root->left->right = new TreeNode(8);
    root->left->right->left = new TreeNode(5);
    root->left->right->left->left = new TreeNode(4);
    root->right = new TreeNode(10);
    root->right->left = new TreeNode(9);
    root->right->left->left = new TreeNode(6);
    cout << "Before recovery : ";
    InorderTraversal(root);
    Recover rt;
    rt.recoverTree(root);
    cout << "\nAfter recovery : ";
    InorderTraversal(root);
    return 0;
}
