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

struct node* ParentMapper_TargetFinder(struct node *root, map<struct node*, struct node*> &parentMap,int targetvalue){
    queue<struct node*> q;
    struct node *target;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        while(size--){
            struct node* tmp = q.front();
            q.pop();
            if(tmp->data == targetvalue) target = tmp;
            if(tmp->left){
                parentMap[tmp->left] = tmp;
                q.push(tmp->left);
            }
            if(tmp->right){
                parentMap[tmp->right] = tmp;
                q.push(tmp->right);
            }
        }
    }
    return target;
}

int min_time_toBurnTree(struct node *root, int targetvalue){
    queue<struct node*> q;
    map<struct node*, struct node*> parentMap;
    struct node *target = ParentMapper_TargetFinder(root,parentMap,targetvalue);
    q.push(target);//push target to queue

    map<struct node*, bool> visited;//map visited nodes
    visited[target] = true;

    int time = 0;//burned target already at 0s

    while(!q.empty()){
        int size = q.size();
        bool burnt = false;
        while(size--){
            struct node *temp = q.front();
            q.pop();
            if(temp->left && !visited[temp->left]){
                visited[temp->left] = true;
                q.push(temp->left);
                burnt = true;
            }
            if(temp->right && !visited[temp->right]){
                visited[temp->right] = true;
                q.push(temp->right);
                burnt = true;
            }
            if(parentMap[temp] && !visited[parentMap[temp]]){
                visited[parentMap[temp]] = true;
                q.push(parentMap[temp]);
                burnt = true;
            }
        }
        if(burnt) //account for time only when something gets burnt
            time++;
    }

    return time;
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

target : 6

6
3
7 1
9 2
4 5
8

time taken = 5 sec.
     */

    cout << "Min time to Burn the given tree : " << min_time_toBurnTree(root, 6) << " s\n\n";

    struct node *root2 = Create(12);
    root2->left = Create(19);
    root2->left->left = Create(41);
    root2->left->left->right = Create(2);
    root2->right = Create(82);
    root2->right->left = Create(15);
    root2->right->left->left = Create(21);
    root2->right->right = Create(95);
    root2->right->right->left = Create(7);
    root2->right->right->right = Create(16);
    /*
                       12
                     /     \
                  19        82
                 /        /     \
               41       15       95
                 \     /         /  \
                  2   21        7   16
target node = 41

Output :
41
2, 19
12
82
15, 95
21, 7, 16    

time = 5 s
*/


    cout << "Min time to Burn the given tree : " << min_time_toBurnTree(root2, 41) << " s\n\n";

    return 0;
}
