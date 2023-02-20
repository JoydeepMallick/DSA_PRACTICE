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


int diameterOpt(struct node *root, int *height){//here nodes are counted not
                                                //edges
    // lh --> Height of left subtree
    // rh --> Height of right subtree
    int lh = 0, rh = 0;
 
    // ldiameter  --> diameter of left subtree
    // rdiameter  --> Diameter of right subtree
    int ldiameter = 0, rdiameter = 0;
 
    if (root == NULL) {
        *height = 0;
        return 0; // diameter is also 0
    }
 
    // Get the heights of left and right subtrees in lh and
    // rh And store the returned values in ldiameter and
    // ldiameter
    ldiameter = diameterOpt(root->left, &lh);
    rdiameter = diameterOpt(root->right, &rh);
 
    // Height of current node is max of heights of left and
    // right subtrees plus 1
    *height = max(lh, rh) + 1;
 
    return max(lh + rh + 1, max(ldiameter, rdiameter));
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
    printf("\nDiameter of binary tree : %d\n",diameterOpt(root,&d));

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
    printf("\nDiameter of binary tree 2 : %d\n",diameterOpt(root2,&d));

    return 0;
}
