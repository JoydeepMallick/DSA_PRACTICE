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

/*
 Height of a tree --> the number of nodes along the longest path from tthe root node down to the farthest leaf node.
 */
int height(struct node *Node){
    if(Node == NULL) return 0;
    else{
        int lheight = height(Node->left);
        int rheight = height(Node->right);
        if(lheight > rheight) return lheight+1;
        else return rheight+1;
    }
}
//print nodes at a current level
void printCurrentLevel(struct node *root, int level){
    if(root == NULL) return;
    if(level == 1) printf("%d ",root->data);
    else if(level > 1){
        printCurrentLevel(root->left, level-1);
        printCurrentLevel(root->right, level-1);
    }
}
//to print level order traversal of a tree
void printLevelOrder(struct node* root){
    int h = height(root);
    int i;
    for(i = 1; i<=h; i++) printCurrentLevel(root,i);
}



int main(){
    struct node* root = Create(1) ;
    root->left = Create(2);
    root->left->left = Create(4);
    root->left->right = Create(5);
    root->right = Create(3);
    root->right->left = Create(6);
    root->right->right = Create(7);
    /*
             1
            / \
           2   3
          /\   /\
         4 5  6  7
     */

    printf("\n\nLevel order traversal using recursion : ");
    printLevelOrder(root);
    return 0;
}
