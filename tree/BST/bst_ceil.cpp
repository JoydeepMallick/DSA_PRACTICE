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

int find_ceil(struct node *root, int key){
    int ceil_val = -1;//not found
    while(root){
        if(root->data == key){
            ceil_val = root->data;
            return ceil_val;
        }
        if(root->data > key){
            ceil_val = root->data;
            root = root->left;//go to left to find a smaller counter part which
                              //is greater than key
        }
        else{
            root = root->right;//go to bigger counter part
        }
    }
    return ceil_val;
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
    cout << find_ceil(root, 3) << "  " << find_ceil(root, 11) << " " << find_ceil(root, 20) << endl;
    return 0;
}
