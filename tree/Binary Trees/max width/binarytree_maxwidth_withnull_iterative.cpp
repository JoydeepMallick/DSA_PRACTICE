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

int maxWidth(struct node *root){
    if(root == NULL) return 0;
    int ans = 0;
    queue<pair<struct node*, int>> q;
    //declare of queue of format {node, node's index}
    q.push({root, 0}); //we use 0 based indexing
    /*
     * left index = 2*i + 1
     * right index = 2*i + 2
     */
    
    //simple level order traversal using queue considering only extreme nodes
    //of each level
    while(!q.empty()){
        int first,last;
        //left and right extreme nodes defined above for each level
        int size = q.size();
        int mmin = q.front().second;
        //stores the index of left extreme node of any level
        //helpful in making the index start from 0 in each level
        //thus avoiding overflow in index value
        for(int i = 0; i < size; i++){
            //we are just conserned with extreme nodes of a level
            int cur_ind = q.front().second - mmin;
            struct node *temp = q.front().first;
            q.pop();//remove node
            if(i == 0) first = cur_ind;
            if(i == size -1) last = cur_ind;

            if(temp->left) q.push({temp->left, cur_ind*2 + 1});
            if(temp->right) q.push({temp->right, cur_ind*2 + 2});
        }
        ans = max(ans, last - first + 1);
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
             1   <--level 0 width = 1
            / \
           2   3  <--level 1  width = 2
          /\   /\
         4 5  6  7  <--level 2 width = 4
           \    /
           8   9      <--level 3  width = 4
    
    max width = 4

*/
    cout << "Max width : " << maxWidth(root) << endl;
    return 0;
}
