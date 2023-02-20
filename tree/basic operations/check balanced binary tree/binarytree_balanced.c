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
    return (x>y)? x : y;
}

int HeightUtil(struct node *root){
    int lh,rh;
    if(root == NULL) return 0;
    lh = HeightUtil(root->left);
    if(lh == -1) return -1;
    rh = HeightUtil(root->right);
    if(rh == -1) return -1;
    
    if(abs(lh-rh) > 1) return -1;//case of imbalance encountered
    else return 1 + max(lh,rh);
}

_Bool isBalanced(struct node *root){
    return (HeightUtil(root) != -1)? 1 : 0;
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

           Balanced tree
     */

    printf("root is balanced : %d\n",isBalanced(root));


    struct node* root2 = Create(1);
    root2->left = Create(2);
    root2->right = Create(3);
    root2->left->left = Create(4);
    root2->left->right = Create(5);
    root2->left->left->left = Create(8);
    /*
            1
           / \
          2   3
         / \
        4   5
       /
      8

      Not  balanced
    */

    printf("root2 is balanced : %d\n",isBalanced(root2));


    return 0;
}
