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

void Inorder(struct node* root){
    if(root == NULL) return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

struct node* build(vector<int> preorder, int &i, int upperbound){
    if(i == preorder.size() || preorder[i] > upperbound) return NULL;//whenever we hit a case when no children can be attached then we need to return NULL
                                                            
    struct node* root = Create(preorder[i++]);
    root->left = build(preorder, i, root->data);
    root->right = build(preorder, i, upperbound);//we are sure preorder BST is valid hence we never hit a case when its less than ancestor
    return root;
}

struct node* CreateBSTfromPreorder(vector<int> preorder){
    int i = 0;
    return build(preorder, i, INT_MAX);
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
    vector<int> preorder = {8, 3, 1, 6, 4, 7, 10, 14, 13};
    struct node* root2 = CreateBSTfromPreorder(preorder);
    cout << "Inorder traversal after creation from preorder : ";
    Inorder(root2);
    cout << endl;

    /*
                8
               /\
              5  10
             /\   \
            1  7   12
     */
    preorder = {8, 5, 1, 7, 10, 12};
    root2 = CreateBSTfromPreorder(preorder);
    cout << "Inorder traversal after creation from preorder : ";
    Inorder(root2);
    cout << endl;

    return 0;
}
