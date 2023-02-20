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

struct node* inorderSuccessor(struct node* root, int val){
    struct node* successor = NULL;
    while(root != NULL){
        //remember we need to find succeessor hence when data in current node is small than vlue we need to move to geater counterpart as it can be the successor
        if(root->data <= val) root = root->right;// = is needed for root assume any example
        else{
            successor = root;
            root = root->left;
        }
    }
    return successor;
}

int main(){
    struct node* root = Create(8) ;
    root->left = Create(3);
    root->left->left = Create(1);
    root->left->right = Create(6);
    root->left->right->left = Create(4);
    root->left->right->right = Create(7);
    root->right = Create(10);
    root->right->right = Create(14);
    root->right->right->left = Create(13);
    /*
             8   <--level 0
            / \
           3   10  <--level 1
          /\    \
         1  6     14  <--level 2
            /\    /
           4  7   13      <--level 3
     */
    cout << "Successor of 13: " << inorderSuccessor(root, 13)->data << endl;
    cout << "Successor of 6: " << inorderSuccessor(root, 6)->data << endl;
    return 0;
}
