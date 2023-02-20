
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

void inorder(struct node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

/* basic concept is to find the null postion of a node wherein  */
void insert(struct node* &root, int val){
    // if no node is present
    if(root==NULL) {
        root = Create(val);
        return;
    }
    struct node* cur = root;
    while(1){
        if(cur->data <= val){
            //must move right
            if(cur->right) cur = cur->right;
            else{
                //a null position encounter hence now insert newnode
                cur->right = Create(val);
                break;
            }
        }
        else{
            //must be on left
            if(cur->left) cur = cur->left;
            else{
                //a null position hence insert
                cur->left = Create(val);
                break;
            }
        }
    }
    //root has been successfully updated inplace
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
    
    cout << "Before insertion : ";
    inorder(root);
    cout << "\nEnter an element to insert : ";
    int ele;
    cin >> ele;//try 0 15 5
    insert(root, ele);
    cout << "\nAfter insertion : ";
    inorder(root);
    cout << endl;
  // output can be verified as an sorted array
    return 0;
}
