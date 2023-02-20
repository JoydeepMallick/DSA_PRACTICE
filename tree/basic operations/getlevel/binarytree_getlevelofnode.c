//C program to get level of binary tree
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

//utility function to find the level of a given node
//if node element is not found then return -1
int getLevelUtil(struct node *Node, int ele, int level){
    int downlevel;
    if(Node == NULL) return -1;//if Node element is not found
    if(Node->data == ele) return level;
    //search in left subtree
    downlevel = getLevelUtil(Node->left, ele, level+1);
    if(downlevel != -1) return downlevel;
    //search in right subtree
    downlevel = getLevelUtil(Node->right, ele, level+1);
    
    return downlevel;
}

int getLevel(struct node *Node, int ele){
    return getLevelUtil(Node, ele, 0);
}

int main(){
    int ele;
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
     */
/*
 //Below code for user input 
 
    printf("\nEnter node element for which level is needed(-1 means not found) : ");
    scanf("%d",&ele);
    printf("\nLevel : %d\n\n",getLevel(root, ele));
*/
    printf("All the node levels are printed below(-1 means node element doesn't exist) :-\n\n");
    for(ele = 0; ele <= 10; ele++){
        printf("Level of %d : %d\n",ele,getLevel(root,ele));
    }
    return 0;
}
