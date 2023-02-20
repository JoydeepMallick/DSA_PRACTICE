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

vector<int> topView(struct node *root){
    vector<int> ans;
    if(root == NULL) return ans;
    map<int,int> maptopNodes;//stores vertical as index and top view nodes
                     //correspondigly
    queue<pair<struct node*, int>> q;//stores nodes and their vertical
    q.push({root,0});
    while(!q.empty()){
        pair<struct node*,int> it = q.front();
        q.pop();
        struct node* temp = it.first;
        int vertical = it.second;
        if(maptopNodes.find(vertical) == maptopNodes.end()) maptopNodes[vertical] = temp->data;//only first occurence gets recorded in map
                                                                          
        if(temp->left) q.push({temp->left, vertical-1});
        if(temp->right) q.push({temp->right, vertical+1});
    }
    //in map indexes are sorted
    for(pair<int,int> it : maptopNodes){
        ans.push_back(it.second);//insert values accrding to vertical indices
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
     
           top view = 4 2 1 3 7
     */
    vector<int> ans = topView(root);
    cout <<"Top view : ";
    for(auto it : ans) cout << it << " ";
    cout << endl;
    return 0;

}
