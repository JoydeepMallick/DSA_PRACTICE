#include<stdio.h>
#include<stdlib.h>

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

void inorderTraversal(struct node *root){
    if(root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ",root->data);
    inorderTraversal(root->right);
}

void replaceNodewithDepth(struct node* root,int curLevel){
    //simple bfs traversal happens where each node when traversed is replaced
    //by the current level
    if(root == NULL) return;
    root->data = curLevel;
    replaceNodewithDepth(root->left, curLevel+1);
    replaceNodewithDepth(root->right, curLevel + 1);
}

int main(){
    struct node* root = Create(1) ;
    root->left = Create(2);
    root->left->left = Create(4);
    root->left->right = Create(5);
    root->right = Create(3);
    root->right->left = Create(6);
    root->right->right = Create(7);
    root->left->right->right = Create(8);
    root->right->right->left = Create(9);
    /*
             1   <--level 0
            / \
           2   3  <--level 1
          /\   /\
         4 5  6  7  <--level 2
           \    /
           8   9      <--level 3
    
           Inorder -> 4 2 5 8 1 6 3 9 7

after replacement ->  2 1 2 3 0 2 1 3 2

*/

    printf("\nInorder traversal of tree : ");
    inorderTraversal(root);
    
    replaceNodewithDepth(root,0);
    printf("\nInorder traversal of tree AFTER replacing nodes with depth/levels : ");
    inorderTraversal(root);
    printf("\n\n\n");


    return 0;
}
