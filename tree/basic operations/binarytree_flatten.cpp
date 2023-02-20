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

void inorder(struct node *root){
    if(root->left) inorder(root->left);
    cout << root->data << " ";
    if(root->right) inorder(root->right);
}

void flatten(struct node* &root){
    struct node* cur = root;
    while(cur!=NULL){
        if(cur->left != NULL){
            struct node* prev = cur->left;
            //go to rightmost child
            while(prev->right) prev = prev->right;
            prev->right = cur->right;
            cur->right = cur->left;//attach left child inplace of right
            cur->left = NULL;//detach left child
        }

        cur = cur->right;
    }
}

void flatten_stack(struct node* &root){
    stack<struct node*> stk;
    stk.push(root);
    while(!stk.empty()){
        struct node* cur = stk.top();
        stk.pop();

        if(cur->right) stk.push(cur->right);
        if(cur->left) stk.push(cur->left);
        if(!stk.empty()){
            cur->right = stk.top();
        }
        cur->left = NULL;
    }
}

void flatten_recur(struct node** root, struct node* &prev){
    if(*root == NULL) return;
    flatten_recur(&(*root)->right, prev);
    flatten_recur(&(*root)->left, prev);
    (*root)->right = prev;
    (*root)->left = NULL;//empty the left child
    prev = *root;
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
     */
    cout << "Before flattening inorder : ";
    inorder(root);
    cout << "\nAfter flattening inorder : ";
    struct node *prev = NULL;
    //flatten_recur(&root, prev);
    //flatten_stack(root);
    flatten(root);
    inorder(root);

    /*
            1
            /\
          2    5
         /\     \
        3  4     6
                /
                7
     */
    struct node *root2 = Create(1);
    root2->left = Create(2);
    root2->left->left = Create(3);
    root2->left->right = Create(4);
    root2->right = Create(5);
    root2->right->right = Create(6);
    root2->right->right->left = Create(7);
    cout << "\n\nBefore flattening inorder : ";
    inorder(root2);
    prev = NULL;
    //flatten_recur(&root2, prev);
    //flatten_stack(root2);
    flatten(root2);
    cout << "\nAfter flattening inorder : ";
    inorder(root2);
    return 0;
}
