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


int diameterOfTree(struct node *root, int *maxdia){
    int lh,rh;
    if(root == NULL) return 0;
    lh = diameterOfTree(root->left, maxdia);
    rh = diameterOfTree(root->right, maxdia);
    *maxdia = max(*maxdia, lh+rh);
    return 1 + max(lh, rh);
}

int main(){
    int d = 0;
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
    diameterOfTree(root, &d);
    printf("\nDiameter of binary tree : %d\n",d);

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
    d = 0;
    diameterOfTree(root2, &d);
    printf("\nDiameter of binary tree 2 : %d\n",d);

    return 0;
}
