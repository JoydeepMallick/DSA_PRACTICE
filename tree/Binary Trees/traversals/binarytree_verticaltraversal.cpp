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
 * best sorts when at same many nodes of same vertical at same level
 */
void verticalTraversal(struct node* root){
    if(root == NULL) return;
    //since vertical order traversal hence x coordinate must be vertical
    queue<pair<struct node*,pair<int, int>>> q;//store the node and (vertical, level)
    
    map<int, map<int,multiset<int>>> ans;//stores coordinate index and correspoding node values
    
    q.push({root, {0, 0}});//root node assumed at vertical 0 level 0
    while(!q.empty()){
        struct node *temp = q.front().first;
        int vert = q.front().second.first;
        int lvl = q.front().second.second;
        q.pop();

        ans[vert][lvl].insert(temp->data);//inserting into map
        if(temp->left){
            q.push({temp->left, {vert-1, lvl+1}});
        }
        if(temp->right){
            q.push({temp->right, {vert+1, lvl+1}});
        }
    }
    for(map<int, map<int, multiset<int>>>::iterator it = ans.begin(); it != ans.end(); it++){
        for(map<int, multiset<int>>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++){
            for(auto ele : it2->second) cout << ele << " ";
        }
        cout << endl;
    }
}



/*
 this sorts values for a particular vertical since its indexed only according to vertical completely and maynot follow levels while sorting hence less efficient use the coordinate(x,y) to work.
 */
void verticalTraversal_ineff(struct node* root){
    if(root == NULL) return;
    queue<pair<struct node*,int>> q;//store the node and vertical count
    map<int,multiset<int>> ans;//stores vertical index and correspodind node
                               //values
    q.push({root, 0});//root node assumed at vertical 0
    while(!q.empty()){
        struct node *temp = q.front().first;
        int vert = q.front().second;
        q.pop();

        ans[vert].insert(temp->data);//inserting into map
        if(temp->left){
            q.push({temp->left, vert-1});
        }
        if(temp->right){
            q.push({temp->right, vert+1});
        }
    }
    for(map<int, multiset<int>>::iterator it = ans.begin(); it != ans.end(); it++){
        for(multiset<int>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++){
            cout << *it2 << " " ;
        }
        cout << endl;
    }
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
          2    3  <--level 1
         /\   /\
        4  5 6  7  <--level 2
           \   /
           8  9      <--level 3

        4
        2
        1 5 6
        3 8 9
        7    
     */

    verticalTraversal(root);
    return 0;
}
