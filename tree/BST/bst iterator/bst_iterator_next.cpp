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

//iterator of bst
class bst_iterator{
    private:
        stack<TreeNode*> bst_stk;

        void pushAll_left(TreeNode* currentnode){
            while(currentnode != NULL){
                bst_stk.push(currentnode);
                currentnode = currentnode->left;//append all leftmost children
            }
        }

    public:
        //constructor of the class use to prepare stack before using
        bst_iterator(TreeNode* root){
            pushAll_left(root);
        }

        bool hasNext(){
            return !bst_stk.empty();
        }
        
        TreeNode* next(){
            if(hasNext()){
                TreeNode* poppednode = bst_stk.top();
                bst_stk.pop();
                pushAll_left(poppednode->right);//if right child is present then push all left
                return poppednode; 
            }
            else return NULL;
        }
};

void inorder(TreeNode* root){
    if(root==NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}


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
/* inorder(root); */

    bst_iterator* bstit = new bst_iterator(root);
    while(1){
        int ch;
        cout << "\n0. Exit\n1. next()\n2. hasNext()\nEnter your choice : ";
        cin >> ch;
        if(ch==0) break;
        else if(ch==1){
            TreeNode* nx = bstit->next();
            if(nx) cout << "\n\tNext value is " << nx->val << endl;
            else cout << "\nNothing to print!!!\n";
        }
        else if(ch==2) cout << boolalpha << "\n\tHas next node in inorder : " << bstit->hasNext() << endl;
        else cout << "\nWrong choice!!!\n";
    }

    return 0;
}
