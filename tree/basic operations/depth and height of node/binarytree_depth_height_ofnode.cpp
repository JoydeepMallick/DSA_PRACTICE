#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left, *right;
};

int max(int x, int y){
    if(x > y) return x;
    else return y;
}

int depthOfNode(struct node *root, int ele){
    //base case
    if(root == NULL) return -1;
    //intialise depth as -1
    int d = -1;
    //check if element in current node
    if((root->data == ele)
            //else if in left subtree
            ||(d = depthOfNode(root->left, ele)) >= 0
            //else if in right subtree
            ||(d = depthOfNode(root->right, ele)) >= 0) return d+1;
    //return depth of node
    return d;
}

int heightOfNodeUtil(struct node *root, int ele,int& h){
    if(root == NULL) return -1;
    //store maximum height of left and right subtree
    int leftHeight = heightOfNodeUtil(root->left, ele,h);
    int rightHeight = heightOfNodeUtil(root->left, ele,h);

    //update height of current node
    int ans = max(leftHeight, rightHeight) + 1;

    //if current node is required node then only store its height
    if(root->data == ele) h = ans;
    return ans;
}

int heightOfNode(struct node *root, int ele){
    int h = -1;
    //max height of tree stored
    int maxheight = heightOfNodeUtil(root, ele, h);
    //printf("-->%d",maxheight);
    //return height
    return h;
}

struct node* Create(int ele){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = ele;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

int main(){
    int i;
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


    for(i = 0; i <= 10; i++) printf("\nDepth of node %d is %d.",i,depthOfNode(root,i));

    printf("\n\n\n");
    for(i = 0; i <= 10; i++) printf("\nHeight of node %d is %d.",i,heightOfNode(root,i));


    struct node* root2 = Create(5);
    root2->left = Create(10);
    root2->right = Create(15);
    root2->left->left = Create(20);
    root2->left->right = Create(25);
    root2->left->right->right = Create(45);
    root2->right->left = Create(30);
    root2->right->right = Create(35);
    /*

                5
                /\
              10  15
             /\    /\
            20 25 30 35
                \
                45
    */
    printf("\n\n\n\n");
    for(i = 5; i <= 45; i+=5) printf("\nDepth of node %d is %d.",i,depthOfNode(root2,i));

    printf("\n\n\n");
    for(i = 5; i <= 45; i+=5) printf("\nHeight of node %d is %d.",i,heightOfNode(root2,i));

    return 0;
}
