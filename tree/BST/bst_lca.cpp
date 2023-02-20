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

//assuming both n1 and n2  are present in binary tree
int findLCA_BST(struct node *root, int n1, int n2){
    if(root == NULL) return NULL;
    if(n1 > root->data && n2 > root->data){
        //deifnitely on right of binary search tree
        return findLCA_BST(root->right, n1, n2);
    }
    else if(n1 < root->data && n2 < root->data){
        //deifnitely on left of BST
        return findLCA_BST(root->left, n1, n2);
    }
    else return root->data;
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

    cout << "LCA of 1 and 4 = " << findLCA_BST(root, 1, 4) << endl;
 
    cout << "LCA of 1 and 1 =  " << findLCA_BST(root, 1, 1) << endl;
 
    cout << "LCA of 4 and 1 = " << findLCA_BST(root, 4, 1) << endl;
 
    cout << "LCA of 10 and 13 = " << findLCA_BST(root, 10, 13) << endl;

    cout << "LCA of 3 and 9 = " << findLCA_BST(root, 3, 9) << endl;//chek if n1 and n2 are present in biarny tree else unexpected output
 
    return 0;
}
