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

/*
 * we need to pass the vector as a reference so that any change in it will get
 * reflected in the actual vector passed to it.
 */
bool findPath(struct node *root, vector<int> &path, int ele){
    if(root == NULL) return false;

    //store this node in path vector, will remove it if not present in path
    //from root to k
    path.push_back(root->data);
    
    //check if root is same as element 
    if(root->data == ele) return true;

    //check if root is found in left or right subtree(hence stacking of path
    //occurs accordingly)
    if((root->left && findPath(root->left, path, ele)) 
            || (root->right && findPath(root->right, path, ele))) return true;

    //if not present in subtree with the current root pop the current root data
    path.pop_back();
    return false;
}

int findLCA(struct node *root, int n1, int n2){
    //returns LCA if both n1 and n2 present in binary tree else return -1
    vector<int> path1, path2;
    if(!findPath(root, path1, n1) || !findPath(root, path2, n2)) return -1;
    int i;
    for( i = 0; i < path1.size() && i < path2.size(); i++){
        if(path1[i] != path2[i]) break;
    }
    return path1[i-1];
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
