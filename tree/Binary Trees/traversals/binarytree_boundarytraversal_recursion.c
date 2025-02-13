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


void printLeaves(struct node* root){
    if(root == NULL) return;
    printLeaves(root->left);
    //print it if it is a leaf node
    if(!(root->left) && !(root->right)) printf("%d ",root->data);
    printLeaves(root->right);
}


void printLeftBoundary(struct node *root){
    if(root == NULL) return;
    if(root->left){
        //to ensure top to down order first print node then go to its left subtree
        printf("%d ",root->data);
        printLeftBoundary(root->left);
    }
    else if(root->right){//if no left child but only right child
        printf("%d ",root->data);
        printLeftBoundary(root->right);
    }
    //when root left and right are NULL do nothing hence avoiding leaf nodes
}

void printRightBoundary(struct node *root){
    if(root == NULL) return;
    if(root->right){
        //to ensume bottom up approach first call right subtree then print the
        //node hence internal stack of nodes occurs causing bottom node to be
        //printed first and top node to be printed at last
        printRightBoundary(root->right);
        printf("%d ",root->data);

    }
    else if(root->left){//if no right child but only left child
        printRightBoundary(root->left);
        printf("%d ",root->data);

    }
    //when root is NULL do nothing hence avoiding leaf nodes
}


void printBoundary(struct node *root){
    if(root == NULL) return;
    printf("%d ",root->data);//print root node
    //in anticlockwise direction first leftBoundary
    printLeftBoundary(root->left);
    //print leaf nodes of left and right subtrees
    printLeaves(root);
    //print rightBoundary
    printRightBoundary(root->right);
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

        Boundary :-
         root = 1
         left = 2
         leaves = 4 8 6 9 
         right = 7 3

         1 2 4 8 6 9 7 3
     */
    printf("\nFor root : ");
    printBoundary(root);




    struct node *root2 = Create(20);
    root2->left = Create(8);
    root2->left->left = Create(4);
    root2->left->right = Create(12);
    root2->left->right->left = Create(10);
    root2->left->right->right = Create(14);
    root2->right = Create(22);
    root2->right->right = Create(25);
    /*
                    20
                    /\
                   8  22
                  /\   \
                 4 12   25
                   /\
                10  14

     boundary :-
      root = 20
      left = 8
      leaves = 4 10 14 25
      right = 22

      20 8 4 10 14 25 22
     */
    printf("\n\nFor root2 : ");
    printBoundary(root2);
    return 0;
}
