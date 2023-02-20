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

vector<int> getPreorder(struct node *root){
    vector<int> preorder;
    struct node *cur = root;
    while(cur != NULL){
       if(cur->left == NULL){
            preorder.push_back(cur->data);
            cur = cur->right;
        }
       else{
            struct node *prev = cur->left;
            while(prev->right && prev->right != cur) prev = prev->right;

            if(prev->right == NULL){
                prev->right = cur;// connect it 
                preorder.push_back(cur->data);
                cur = cur->left;
            }
            else{
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }
    return preorder;
}



vector<int> getInorder(struct node *root){
    vector<int> inorder;
    struct node *cur = root;
    while(cur != NULL){
        /*
         if no left child then insert current node value and update node to the right child.
         */
        if(cur->left == NULL){
            inorder.push_back(cur->data);
            cur = cur->right;
        }
        /*
if left child is present then set prev pointer to point at left child.
now is prev pointer has right child and prev right 
         */
        else{
            struct node *prev = cur->left;
            while(prev->right && prev->right != cur) prev = prev->right;

            if(prev->right == NULL){
                prev->right = cur;// connect it 
                cur = cur->left;
            }
            else{
                prev->right = NULL;
                inorder.push_back(cur->data);
                cur = cur->right;
            }
        }
    }
    return inorder;
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
           /  ^ \
         2    |   3  <--level 1
        /^\   |  /^\
       4_| 5  | 6 | 7  <--level 2
           \  | / |
           8__|9__|      <--level 3
     */

    for(auto ele : getInorder(root)){
        cout << ele << " ";
    }
    cout << endl;
 

    for(auto ele : getPreorder(root)){
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}
