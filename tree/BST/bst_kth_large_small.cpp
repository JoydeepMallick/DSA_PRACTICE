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
//simple inorder traversal with counter set time and space O(n) and O(h) stack space
struct node* kth_largest_reversedinorder(struct node* root, int& k){
  	if(root==NULL) return NULL;
	
	struct node* rightchild=kth_largest_reversedinorder(root->right,k);
	if(rightchild != NULL) return rightchild;
	k--;
	
	if(k==0) return root;
	
	return kth_largest_reversedinorder(root->left,k);  
}


struct node* kth_smallest_inorder(struct node* root, int& k){
    if(root == NULL) return NULL;
	
	struct node* leftchild = kth_smallest_inorder(root->left,k);

	if(leftchild != NULL) return leftchild;
	k--;//decrement count
	
    if(k==0) return root;
	
	return kth_smallest_inorder(root->right,k);
}


//morris traversal to redu r space complexity to O(1)
//to be done yet not done

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
    int k;
    cout << "Enter value of k : ";
    cin >> k;
    int actualk = k;
    cout << "\n" << k <<"th smallest : " << kth_smallest_inorder(root, k)->data << endl;
    k = actualk;
    cout << "\n" << k <<"th largest : " << kth_largest_reversedinorder(root, k)->data << endl;


    return 0;
}
