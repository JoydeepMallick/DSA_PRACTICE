#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

Node* Create(int ele){
    Node *newnode = new Node;
    newnode->data = ele;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

bool isLeaf(Node *node){
    if(!(node->left) && !(node->right)) return true;
    else return false;
}

void addLeftBound(Node *root, vector<int>& ans){
    //always go to left child if not present to right
    root = root->left;
    while(root != NULL){
        if(!isLeaf(root)) ans.push_back(root->data);
        if(root->left != NULL) root = root->left;
        else root = root->right;
    }
}
void addRightBound(Node *root, vector<int>& ans){
    stack<int> stk;//since we are considered with anticlockwise rotation hence
                   //we use stack for right boundary storage
    //always go to right child if not present to left
    root = root->right;
    while(root != NULL){
        if(!isLeaf(root)) stk.push(root->data);
        if(root->right != NULL) root = root->right;
        else root = root->left;
    }
    while(!stk.empty()){
        ans.push_back(stk.top());
        stk.pop();
    }
}
void addLeaves(Node *root, vector<int>& ans){
    if(root == NULL) return;
    if(isLeaf(root)) {
        ans.push_back(root->data);
        return;
    }
    addLeaves(root->left, ans);
    addLeaves(root->right, ans);
}

vector<int> boundary(Node *root){
    vector<int> ans;
    if(root == NULL) return ans;
    if(!isLeaf(root)) ans.push_back(root->data);//used to push root
    addLeftBound(root, ans);
    addLeaves(root, ans);
    addRightBound(root, ans);
    return ans;
}


int main(){
    Node* root = Create(1) ;
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

        Boundary :-
         root = 1
         left = 2
         leaves = 4 8 6 9 
         right = 7 3

         1 2 4 8 6 9 7 3
     */
    cout << "\nFor root : ";
    vector<int>ans = boundary(root);
    for(int v : ans) cout << v << " ";



    Node *root2 = Create(20);
    root2->left = Create(8);
    root2->left->left = Create(4);
    root2->left->right = Create(12);
    root2->left->right->left = Create(10);
    root2->left->right->right = Create(14);
    root2->right = Create(22);
    root2->right->right = Create(25);
    /*
                    20
                    /\
                   8  22
                  /\   \
                 4 12   25
                   /\
                10  14

     boundary :-
      root = 20
      left = 8
      leaves = 4 10 14 25
      right = 22

      20 8 4 10 14 25 22
     */
    cout << "\n\nFor root2 : ";
    ans = boundary(root2);
    for(int v : ans) cout << v << " ";

    return 0;
}
