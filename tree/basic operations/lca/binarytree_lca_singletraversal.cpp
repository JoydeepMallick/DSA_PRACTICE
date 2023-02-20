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

int findLCAUtil(struct node *root, int n1, int n2){
    if(root == NULL) return NULL;
    if(root->data == n1 || root->data == n2) return root->data;
    int left,right;
    left = findLCAUtil(root->left,n1,n2);
    right = findLCAUtil(root->right,n1,n2);
    //if both not null return root data
    if(left && right){
        return root->data;
    }
    //else try returning non null value if possible else null
    else return (!left)? right : left;
    
}

bool searchNode(struct node *root, int n){//simple bfs
    if(root == NULL) return false;
    else if(root->data == n || searchNode(root->left,n) || searchNode(root->right,n)) return true;
    return false;//node not found
}

int findLCA(struct node *root, int n1, int n2){
    if(searchNode(root,n1) && searchNode(root,n2)) return findLCAUtil(root,n1,n2);
    else return -1;
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


           lca(8,9) = 1
           lca(8,2) = 2
           lca(6,9) = 3
     */
    
    printf("lca(8,9) = %d\n",findLCA(root,8,9));
    printf("lca(8,2) = %d\n",findLCA(root,8,2));
    printf("lca(6,9) = %d\n",findLCA(root,6,9)); 
    printf("lca(1,1) = %d\n",findLCA(root,1,1));
    printf("lca(5,10) = %d\n",findLCA(root,5,10));

    return 0;
}
