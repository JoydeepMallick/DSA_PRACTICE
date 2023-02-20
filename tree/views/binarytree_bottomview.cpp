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

vector<int> bottomView(struct node *root){
    vector<int> ans;
    if(root == NULL) return ans;
    map<int,int> mapbottomNodes;//stores vertical as index and top view nodes
                     //correspondigly
    queue<pair<struct node*, int>> q;//stores nodes and their vertical
    q.push({root,0});
    while(!q.empty()){
        pair<struct node*,int> it = q.front();
        q.pop();
        struct node* temp = it.first;
        int vertical = it.second;
        mapbottomNodes[vertical] = temp->data;//only last occurence gets recorded in map
                                                                          
        if(temp->left) q.push({temp->left, vertical-1});
        if(temp->right) q.push({temp->right, vertical+1});
    }
    //in map indexes are sorted
    for(pair<int,int> it : mapbottomNodes){
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
          / \  /\
         4  5 6  7  <--level 2
            \   /
             8 9      <--level 3
     
           bottom view = 4 2 6 9 7 

           in predicted 4 2 5/6 8/9 7 the  latest nodes traversed get below in bottom view since right is traversed after left.

     */
    vector<int> ans = bottomView(root);
    cout <<"Bottom view : ";
    for(auto it : ans) cout << it << " ";
    cout << endl;
    return 0;

}
