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

void inOrderTraversal(struct node *root){
    if(root==NULL) return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);    
}

struct node *construct(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int> inMap){
    if(preStart > preEnd || inStart > inEnd) return NULL;
    struct node *root = Create(preorder[preStart]);//start of preorder is the current root
    
    int inRoot = inMap[root->data];//indexof current root
    int numsleft = inRoot - inStart;//no of nodes in left subtree
    //if current inorder [...root....] the elements of first half before root counted
    /*
preorder :-
-----------------------------------
[root, {left nodes}, {rightnodes}]

for left subtree :-  preStart+1 till preStart + numsleft
for right subtree :- preStart + numsleft  till   END(valid always!!!)

inorder :-
-----------------------------------
[{left nodes}, root, {right nodes}]

for left subtree :- 0(always!!!)  till   indexofcurrentNode -1
for right subtree :- indexofcurrentNode +1   till    END(valid always!!!)

     */
    root->left = construct(preorder, preStart +1, preStart + numsleft, inorder, inStart, inRoot-1, inMap);

    root->right = construct(preorder, preStart + numsleft + 1, preEnd, inorder, inRoot +1, inEnd, inMap);

    return root;
}

struct node *construct(vector<int>& preorder, vector<int>& inorder){
    unordered_map<int, int> inMap;
    for(int i = 0; i < inorder.size(); i++) inMap[inorder[i]] = i;

    struct node *root = construct(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
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
    vector<int> preorder = {10, 20, 40, 50, 30, 60};
    
    struct node *root = construct(preorder, inorder);
    inOrderTraversal(root);
    return 0;
}
