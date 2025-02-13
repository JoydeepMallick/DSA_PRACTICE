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

int max(int x,int y){
    if(x>y) return x;
    else return y;
}

int height(struct node *root){
    if(root == NULL) return 0;
    return 1 + max(height(root->left), height(root->right));
}

int diameterOfTree(struct node *root){
    int lh,rh,ld,rd;
    if(root == NULL) return 0;
    lh = height(root->left);
    rh = height(root->right);
    
    ld = diameterOfTree(root->left);
    rd = diameterOfTree(root->right);
    return max(lh+rh, max(ld,rd));//in terms of edges
    //return max(lh+rh+1, max(ld,rd));//in terms of nodes
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

           diameter of tree = 6 (from node 8 to node 9 via root 1)
     */

    printf("\nDiameter of binary tree : %d\n",diameterOfTree(root));

    struct node* root2 = Create(1);
    root2->left = Create(2);
    root2->left->left = Create(4);
    root2->left->right = Create(5);
    root2->right = Create(3);
    /*
           1
          /\
         2 3
        /\
       4 5

       Diameter of tree = 3

     */

    printf("\nDiameter of binary tree 2 : %d\n",diameterOfTree(root2));

    return 0;
}
