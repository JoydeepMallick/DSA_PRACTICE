#include <bits/stdc++.h>
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
    if(root==NULL) return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);    
}

struct node *construct(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart,  int inEnd, unordered_map<int, int> inMap){
    if(postStart > postEnd || inStart > inEnd) return NULL;
    struct node *root = Create(postorder[postEnd]);//end of postorder is the current root
    
    int inRoot = inMap[root->data];//indexof current root
    int numsleft = inRoot - inStart;//no of nodes in left subtree
    //if current inorder [...root....] the elements of first half before root counted
    /*
postorder :-
-----------------------------------
[{left nodes}, {rightnodes}, root]

for left subtree :-  0(always!!!) till postStart + numsleft
for right subtree :- postStart + numsleft  till   lastindex-1

inorder :-
-----------------------------------
[{left nodes}, root, {right nodes}]

for left subtree :- 0(always!!!)  till   indexofcurrentNode -1
for right subtree :- indexofcurrentNode +1   till    END(valid always!!!)

     */
    root->left = construct(postorder, postStart, postStart + numsleft -1, inorder, inStart, inRoot-1, inMap);

    root->right = construct(postorder, postStart + numsleft, postEnd-1, inorder, inRoot +1, inEnd, inMap);

    return root;
}

struct node *construct(vector<int>& postorder, vector<int>& inorder){
    unordered_map<int, int> inMap;
    //map the inorder indices
    for(int i = 0; i < inorder.size(); i++) inMap[inorder[i]] = i;

    struct node *root = construct(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, inMap);
    return root;
}


int main(){
       /*
             10   <--level 0
            / \
           20  30  <--level 1
          /\   /
        40 50 60    <--level 2
     */
    vector<int> inorder = {40, 20, 50, 10, 60, 30};
    vector<int> postorder = {40, 50, 20, 60, 30, 10};
    
    struct node *root = construct(postorder, inorder);
    cout << "After construction inorder traversal of root : " ;
    inOrderTraversal(root); 
    cout << endl;
    return 0;
}

