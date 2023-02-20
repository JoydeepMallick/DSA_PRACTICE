#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left, *right;
};

struct node* Create(int ele){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = ele;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

bool checkBST(struct node* root,int leftrange, int rightrange){
    //check for current root
    if(root == NULL) return true;
    if(leftrange < root->data && root->data < rightrange){
        if( checkBST(root->left, leftrange, root->data) && checkBST(root->right, root->data, rightrange) ) return true;
        else return false;
    }
    else return false;
    
}

//striver code

bool isValid(struct node* root, int mn, int mx){
    if(root == NULL) return true;
    if(mn >= root->data || root->data >= mx) return false;
    return isValid(root->left, mn, root->data) && isValid(root->right, root->data, mx);
}

bool checkBST_alt(struct node *root){
    return isValid(root, INT_MIN, INT_MAX);
}

int main(){
    struct node* root = Create(8) ;
    root->left = Create(3);
    root->left->left = Create(1);
    root->left->right = Create(6);
    root->left->right->left = Create(4);
    root->left->right->right = Create(7);
    root->right = Create(10);
    root->right->right = Create(14);
    root->right->right->left = Create(13);
    /*
             8   <--level 0
            / \
           3   10  <--level 1
          /\    \
         1  6     14  <--level 2
            /\    /
           4  7   13      <--level 3
     */
    cout << "IS ROOT BST ? " << boolalpha << checkBST(root, INT_MIN, INT_MAX) << " " << checkBST_alt(root) << endl;

    struct node* root2 = Create(13);
    root2->left = Create(10);
    root2->right = Create(15);
    root2->left->left = Create(7);
    root2->left->right = Create(12);
    root2->left->left->right = Create(9);
    root2->left->left->right->left = Create(8);
    root2->right->left = Create(14);
    root2->right->right = Create(17);
    root2->right->right->left = Create(16);
    /*
                    13
                   /  \
                 10    15
                / \    / \
               7  12  14  17
               \          /
                9         16
               /
              8
     */
    cout << "IS ROOT2 BST ? " << checkBST(root2, INT_MIN, INT_MAX) << " " << checkBST_alt(root2) << endl;

    return 0;
}
