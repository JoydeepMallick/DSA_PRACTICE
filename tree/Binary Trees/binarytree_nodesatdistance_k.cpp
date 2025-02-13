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


//marks all the parents of each child node except for root
//will help in going up and counting the the number of nodes visited
void markParents(struct node *root, unordered_map<struct node*,struct node*>& parent_track, struct node *target){
    queue<struct node*> q;
    q.push(root);
    while(!q.empty()){
        struct node *current = q.front();
        q.pop();
        if(current->left){
            parent_track[current->left] = current;
            q.push(current->left);
        }
        if(current->right){
            parent_track[current->right] = current;
            q.push(current->right);
        }
    }
}

vector<int> element_at_distancek(struct node *root, struct node *target, int k){
    unordered_map<struct node*, struct node*> parent_track;
    markParents(root, parent_track, target);
    //stores record of nodes already visited
    unordered_map<struct node*,bool> visited;
    queue<struct node*> q;
    q.push(target);
    visited[target] = true;
    int curr_level = 0;

    while(!q.empty()){
        int size = q.size();
        if(curr_level++ == k) break;
        for(int i = 0; i < size; i++){
            struct node *current = q.front();
            q.pop();
            if(current->left && !visited[current->left]){
                q.push(current->left);
                visited[current->left] = true;
            }
            if(current->right && !visited[current->right]){
                q.push(current->right);
                visited[current->right] = true;
            }
            if(parent_track[current] && !visited[parent_track[current]]){
                q.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
    }
    vector<int> res;
    while(!q.empty()){
        struct node *current = q.front();
        q.pop();
        res.push_back(current->data);
    }
    return res;
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

           for target as node 2 and distance k as 2
           ans = 8 3
     */

    vector<int> ans = element_at_distancek(root,root->left, 2);
    for(int ele : ans) cout << ele << " ";
    return 0;
}
