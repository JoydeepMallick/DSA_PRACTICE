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

void leftView(struct node *root, int level, vector<int>& ans){
    if(root == NULL) return;
    if(ans.size() == level) ans.push_back(root->data);
    //if size of vector is same as level assuming level starts from 0                                                  
    leftView(root->left, level+1, ans);
    leftView(root->right, level+1, ans);
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
     
           left view = 1 2 4 8
     */
    vector<int> ans;
    leftView(root,0,ans);
    cout <<"Left view : ";
    for(auto it : ans) cout << it << " ";
    cout << endl;
    return 0;

}
