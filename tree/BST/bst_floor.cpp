
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

int find_floor(struct node *root, int key){
    int floor_val = -1;//not found
    while(root){
        if(root->data == key){
            floor_val = root->data;
            return floor_val;
        }
        if(root->data < key){
            floor_val = root->data;
            root = root->right;//go to right to find a larger counter part which
                              //is smaller than key
        }
        else{
            root = root->left;//go to smaller  part in left
        }
    }
    return floor_val;
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
    cout << find_floor(root, 3) << "  " << find_floor(root, 11) << " " << find_floor(root, 0) << endl;
    return 0;
}
