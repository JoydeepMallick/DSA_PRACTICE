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

void inOrderTraversal(struct node *root){
    if(root == NULL) return;
    inOrderTraversal(root->left);
    printf("%d ",root->data);
    inOrderTraversal(root->right);
}

void convert(struct node *root){
    if(root == NULL) return;
    int childsum = 0;
    if(root->left) childsum += root->left->data;
    if(root->right) childsum += root->right->data;
    if(root->data > childsum){
        if(root->left) root->left->data = root->data;//update children with
                                                     //value AT parent node
        if(root->right) root->right->data = root->data;
    }
    //now traverse the subtrees
    convert(root->left);
    convert(root->right);

    //while returning back now add from child nodes and put the sum in parent
    childsum = 0;
    if(root->left) childsum += root->left->data;
    if(root->right) childsum += root->right->data;
    //if not leaf nodes then put the child sum value in parent node
    if(root->left || root->right) root->data = childsum;

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
             1   <--level 0                27
            / \                          /   \
           2   3  <--level 1           12     15
          /\   /\                     /\      /\
         4 5  6  7  <--level 2      4   8   6   9
           \    /                        \     /
           8   9      <--level 3          8    9
    
           Inorder traversal = 4 2 5 8 1 6 3 9 7

           After conversion,   4 12 8 8 27 15 6 9 9

     */

    struct node* root2 = Create(20);
    root2->left = Create(5);
    root2->right = Create(10);
    root2->right->left = Create(8);
    /*
     *      20             40
     *      / \          /  \
     *    5   10        20  20    20
     *        /                   /
     *       8                   20
     *
     *       before = 5 20 8 10
     *       after  = 20 40 20 20
     */
    cout << "Inorder traversal before conversion : " ;
    inOrderTraversal(root2);
    cout << "\n\nInorder traversal after conversion : ";
    convert(root2);//kind of pass by reference since we pass pointer to pointer
    inOrderTraversal(root2);
    
    cout << "\n\n\nInorder traversal before conversion : " ;
    inOrderTraversal(root);
    cout << "\n\nInorder traversal after conversion : ";
    convert(root);//kind of pass by reference since we pass pointer to pointer
    inOrderTraversal(root);

    return 0;
}
