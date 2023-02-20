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
        //true means prev element
        //false means next element
        bool rev_inorder = true;

        void pushAll(TreeNode* currentnode){//kind of performing inorder or reverse inorder
            while(currentnode != NULL){
                bst_stk.push(currentnode);

                if(rev_inorder == true) currentnode = currentnode->right;//append all rightmost children
                else currentnode = currentnode->left;
            }
        }

    public:
        //constructor of the class use to prepare stack before using
        bst_iterator(TreeNode* root, bool rev){
            rev_inorder = rev;
            pushAll(root);
        }

        bool isEmpty(){
            return !bst_stk.empty();
        }
        
        int next(){//find next element may be next or prev
            if(!isEmpty()){
                TreeNode* poppednode = bst_stk.top();
                bst_stk.pop();
                if(rev_inorder == true) pushAll(poppednode->left);//if left child is present then push all right
                else pushAll(poppednode->right);//if right child is present then push all left
                return poppednode->val;
            }
        }
};

void inorder(TreeNode* root){
    if(root==NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

bool findTargets(TreeNode* root, int k){
    if(root == NULL) return false; // not found

    /* Creating two objects of type Bstiterator one for front and other for back... */
    bst_iterator start(root, false);//normal inorder
    bst_iterator end(root, true);//reverse inorder
                                 
    int i = start.next();
    int j = end.next();

    while(i < j){
        //normal two pointer approach
        if(i+j == k) return true;
        else if(i+j < k) i = start.next();//move one step from front in inorder fashion
        else j = end.next();//move one step from end in reverse inorder fashion
    }
    return false;//such a pair not found
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
    int k;
    cout << " Enter two sum value : ";
    cin >> k;
    if(findTargets(root, k)) cout << "2 such nodes found!!!\n";
    else cout << "Sorry!!!no such node\n";

    return 0;
}
