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

void preorder(struct node *Node){
    if(Node == NULL) {
        return;
    }
    else{
        //print data of node
        printf("%d ",Node->data);
        //traverse left subtree recursively
        preorder(Node->left);
        //traverse right subtree recursively
        preorder(Node->right);
    }
}

void inorder(struct node *Node){
    if(Node == NULL) return;
    else{
        //traverse left subtree recursively
        inorder(Node->left);
        //print data of node
        printf("%d ",Node->data);
        //traverse right subtree recursively
        inorder(Node->right);
    }
}

void postorder(struct node *Node){
    if(Node == NULL) return;
    else{
        //traverse left subtree recursively
        postorder(Node->left);
       //traverse right subtree recursively
        postorder(Node->right);
         //print data of node
        printf("%d ",Node->data);
        
    }
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

    printf("\nPreorder traversal : ");
    preorder(root);
 
    printf("\n\nInorder traversal : ");
    inorder(root);   

    printf("\n\nPostorder traversal : ");
    postorder(root);
    return 0;
}
