
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

//declaring neccesary templates
struct node* recreateBST(struct node*);
struct node* findRightmost(struct node*);

void inorder(struct node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void deleteNode(struct node* &root, int val){
    if(root == NULL) return;
    else if(root->data == val) {
        root = recreateBST(root);
        return;
    } 
    //search for val in tree since it wasn't the root node
    struct node *cur = root;
    while(cur != NULL){
        //perform binary search
        /*
         we are sure that root is not the value
         hence we are avoiding the case to check root again

         hence for the first iteration in while loop we can defintely say that root's value is either smaller or greater than given value to delete...

         */
        if(cur->data > val){
            if(cur->left != NULL && cur->left->data == val){
                //if left child of current has to be deleted
                cur->left = recreateBST(cur->left);
                return;
            }
            else{
                //simply update cur
                cur = cur->left;
            }
        }
        else{
            if(cur->right != NULL && cur->right->data == val){
                //if right child of current is to be deleted
                cur->right = recreateBST(cur->right);
                return;
            }
            else{
                //simply update cur
                cur = cur->right;
            }
        }
    }
    //if element to be deleted is not found
    cout << "Element to be deleted not found!!!\n\n No deletion possible!!!\n";

}

struct node* recreateBST(struct node* root){
    //if only one child or no child
    if(root->left == NULL) return root->right;
    else if(root->right == NULL) return root->left;
    //if both child present
    struct node* rightmostchild_of_left = findRightmost(root->left);//find rightmost child of left
    //connect right child of rightmostchild_of_left to root->right
    rightmostchild_of_left->right = root->right;
    return root->left;//send root's left child 
}

struct node* findRightmost(struct node* root){
    while(root->right != NULL){
        root = root->right;
    }
    return root;
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
    
    cout << "Before deletion : ";
    inorder(root);
    cout << "\nEnter an element to delete : ";
    int ele;
    cin >> ele;//try 14 8 3 89
    deleteNode(root, ele);
    cout << "\nAfter deletion : ";
    inorder(root);
    cout << endl;
  // output can be verified as an sorted array
    return 0;
}
