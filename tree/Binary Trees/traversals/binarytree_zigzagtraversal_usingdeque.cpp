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

vector<int> zigzagTraversal(struct node *root){
    //similar to level order traversal using queue
    deque<struct node*> dq;
    vector<int> ans;
   
    if(root==NULL) return ans;
    
    dq.push_back(root);
    ans.push_back(root->data);
    bool lefttoright = true;//root at first level hence popping from left to
                            //right
    while(!dq.empty()){
        int size = dq.size();
        
        while(size--){
            struct node* temp;
            //pop element according to current level either from front or back
            if(lefttoright){
                temp = dq.front();
                dq.pop_front();
            }
            else{
                temp = dq.back();
                dq.pop_back();
            }

            //push elements according to next level hence when current level is
            //left to right we need to store children from right to left
            if(!lefttoright){
                if(temp->left) {
                    dq.push_front(temp->left);
                    ans.push_back(temp->left->data);
                }
                if(temp->right) {
                    dq.push_front(temp->right);
                    ans.push_back(temp->right->data);
                }
            }
            else{
                if(temp->right) {
                    dq.push_back(temp->right);
                    ans.push_back(temp->right->data);
                }
                if(temp->left) {
                    dq.push_back(temp->left);
                    ans.push_back(temp->left->data);
                }
            }
        }
        lefttoright = !lefttoright;//reverse the current value    
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

           1 3 2 4 5 6 7 9 8
     */
    vector<int> ans = zigzagTraversal(root);
    cout << "\n\nZigZag traversal : ";
    for(auto ele : ans) cout << ele << " ";
    cout << endl;
    return 0;
}
