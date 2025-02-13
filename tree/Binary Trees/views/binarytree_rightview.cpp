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

vector<int> rightView(struct node *root){
    vector<int> ans;
    if(root == NULL) return ans;
    queue<struct node*> q;//stores nodes
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        while(size--){
            struct node *temp = q.front();
            q.pop();
            if(size==0) ans.push_back(temp->data);//the last element of
                                                  //particular level
                                                                          
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
   
    return ans;
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
     
           right view = 1 3 7 9
     */
    vector<int> ans = rightView(root);
    cout <<"Right view : ";
    for(auto it : ans) cout << it << " ";
    cout << endl;
    return 0;

}
