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

int maxWidth(struct node *root){
    if(root == NULL) return 0;
    int size,maxw = 0;
    queue<struct node*> q;
    q.push(root);

    while(!q.empty()){
        size = q.size();
        maxw = max(size,maxw);
        //perform simple levelorder traversal
        while(size--){
            struct node *temp = q.front();
            q.pop();//removed front node
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }

    return maxw;
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

           max width in level2 = 4
     */

    cout << "Max width in GFG method : " << maxWidth(root) << endl;
    return 0;
}
