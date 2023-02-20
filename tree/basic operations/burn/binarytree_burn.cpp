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

void ParentMapper(struct node *root, map<struct node*, struct node*> &parentMap){
    queue<struct node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        while(size--){
            struct node* tmp = q.front();
            q.pop();
        
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
}

pair<int,vector<vector<int>>> BurnTree(struct node *root, struct node *target){
    queue<struct node*> q;
    map<struct node*, struct node*> parentMap;
    ParentMapper(root,parentMap);
    q.push(target);
    vector<vector<int>> ans;
    map<struct node*, bool> visited;
    ans.push_back({target->data});
    int time = 1;//burned target already
    while(!q.empty()){
        int size = q.size();
        vector<int> nthburn;
        while(size--){
            struct node *temp = q.front();
            q.pop();
            //mark as visited
            visited[temp] = true;
            if(temp->left && !visited[temp->left]){
                nthburn.push_back(temp->left->data);
                q.push(temp->left);
            }
            if(temp->right && !visited[temp->right]){
                nthburn.push_back(temp->right->data);
                q.push(temp->right);
            }
            if(parentMap[temp] && !visited[parentMap[temp]]){
                nthburn.push_back(parentMap[temp]->data);
                q.push(parentMap[temp]);
            }
        }
        if(nthburn.size()) {//account for time only when something gets burnt
            ans.push_back(nthburn);
            time++;
        }
    }

    return {time, ans};
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

time taken = 6 sec.
     */

    pair<int, vector<vector<int>>> ans = BurnTree(root, root->right->left);
    int t = ans.first;
    cout << "Burn the given tree :-\n\n";
    for(auto it : ans.second){
        for(auto ele : it) cout << ele << " ";
        cout << endl;
    }
    cout << "\nTime Taken to burn : " << t << "sec.\n\n";

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
*/

    ans = BurnTree(root2, root2->left->left);
    t = ans.first;
    cout << "Burn the given tree :-\n\n";
    for(auto it : ans.second){
        for(auto ele : it) cout << ele << " ";
        cout << endl;
    }
    cout << "\nTime Taken to burn : " << t << "sec.\n\n";

    return 0;
}
