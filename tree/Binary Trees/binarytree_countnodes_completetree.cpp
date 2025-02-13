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

int leftheight(struct node *root){
    int lh = 0;
    while(root){
        lh++;
        root = root->left;
    }
    //we go left and left until we end up as null, remember its a complete
    //binary tree
    return lh;
}

int rightheight(struct node *root){
    int rh = 0;
    while(root){
        rh++;
        root = root->right;
    }
    //we go right and right until we face null
    return rh;
}

int countTotalNodes(struct node *root){
    if(root == NULL) return 0;
    int lh = leftheight(root);
    int rh = rightheight(root);
    if(lh == rh) return (1 << lh)-1;
    else return 1 + countTotalNodes(root->left) + countTotalNodes(root->right);
    //add current node + the nodes in leftsubtree + the  nodes in rightsubtree
}

int main(){
    struct node* root = Create(1) ;
    root->left = Create(2);
    root->left->left = Create(4);
    root->left->right = Create(5);
    root->right = Create(3);
    root->right->left = Create(6);
    root->right->right = Create(7);
    root->left->left->left = Create(8);
    root->left->left->right = Create(9);
    root->left->right->left = Create(10);
    root->left->right->right = Create(11);
    /*
             1   <--level 0
            / \
           2   3  <--level 1
          /\   /\
         4 5  6  7  <--level 2
       /\  /\    
      8 9 10 11     <--level 3

      answer = 11
      complete binary tree
*/

    cout << "total nodes in the given tree : " << countTotalNodes(root) << "\n\n";
    return 0;
}
