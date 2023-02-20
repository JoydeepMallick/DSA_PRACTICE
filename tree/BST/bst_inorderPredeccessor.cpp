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

struct node* inorderPredeccessor(struct node* root, int val){
    struct node* predeccessor = NULL;
    while(root != NULL){
        //remember we need to find predeccessor hence when data in current node is greater than value we need to move to smaller counterpart as it can be the predeccessor
        if(root->data >= val) root = root->left;// = is needed for root assume any example
        else{
            predeccessor = root;
            root = root->right;
        }
    }
    return predeccessor;
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
    cout << "Predeccessor of 13: " << inorderPredeccessor(root, 13)->data << endl;
    cout << "Predeccessor of 6: " << inorderPredeccessor(root, 6)->data << endl;
   
    cout << "Predeccessor of 1: " << (inorderPredeccessor(root, 1)?"print data in it" : "NULL") ;//null is returned
    cout << endl; 
    return 0;
}
