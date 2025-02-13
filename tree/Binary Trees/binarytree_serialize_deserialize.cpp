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

void inorderTraversal(struct node *root){
    if(root == NULL) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

string serialize(struct node *root){
    if(!root) return "";

    string s = "";
    queue<struct node*> q;
    q.push(root);
    while(!q.empty()){
        struct node *current = q.front();
        q.pop();
        if(current == NULL) s.append("#,");
        else{
            s.append(to_string(current->data) + ",");
            q.push(current->left);
            q.push(current->right);
        }
    }

    cout <<"serialised string : "<< s << endl;
    return s;
}

struct node* deserialize(string data){
    if(data.size() == 0) return NULL;
    stringstream s(data);
    string str;
    getline(s, str, ',');
    struct node *root = Create(stoi(str));
    queue<struct node*> q;
    q.push(root);

    while(!q.empty()){
        struct node *temp = q.front();
        q.pop();
        // left child
        getline(s, str, ',');
        if(str == "#") temp->left = NULL;
        else {
            temp->left = Create(stoi(str));
            q.push(temp->left);
        }
        // right child
        getline(s, str, ',');
        if(str == "#") temp->right = NULL;
        else {
            temp->right = Create(stoi(str));
            q.push(temp->right);
        }
    }
    return root;
}

/* terminate called after throwing an instance of 'std::invalid_argument' 
 what():  stoi 
 It’s giving an error because the stoi() function encounters a whitespace character before 1. */

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
     */

    string s = serialize(root);
    struct node *root2 = deserialize(s);
    deserialize(s);
    //expected inorderTraversal 
    // 4 2 5 8 1 6 3 9 7
    inorderTraversal(root2);
    return 0;
}
