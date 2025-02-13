#include<stdio.h>
#include<stdlib.h>

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

int max(int x,int y){
    return (x>y)?x:y;
}

int maxPathSum(struct node *root, int *maxi){
    if(root == NULL) return 0;
    int leftsum = maxPathSum(root->left, maxi);
    int rightsum = maxPathSum(root->right, maxi);
    *maxi = max(*maxi, leftsum +rightsum +root->data);
    //path sum is the max heght from left and right subtrees of a particular node
    return (root->data + max(leftsum, rightsum));
}

int main(){
    struct node* root = Create(-10) ;
    root->left = Create(2);
    root->left->left = Create(4);
    root->left->right = Create(5);
    root->right = Create(3);
    root->right->left = Create(6);
    root->right->right = Create(7);
    root->left->right->right = Create(8);
    root->right->right->left = Create(9);
    /*
             -10   <--level 0
            / \
           2   3  <--level 1
          /\   /\
         4 5  6  7  <--level 2
           \    /
           8   9      <--level 3

           max path sum = 6 + 3+ 7+ 9 = 25
     */
    int ans = 0;
    maxPathSum(root,&ans);
    printf("Max path sum : %d\n\n",ans);


    struct node* root2 = Create(-10);
    root2->left = Create(9);
    root2->right = Create(20);
    root2->right->left = Create(15);
    root2->right->right = Create(7);
   /*
          -10
          /\
        9  20
           /\
         15  7

         max path sum = 42
    */
    ans = 0;
    maxPathSum(root2,&ans);
    printf("Max path sum : %d\n\n",ans);

    struct node* root3 = Create(-10);
    root3->left = Create(-9);
    root3->right = Create(-20);
    root3->right->left = Create(-15);
    root3->right->right = Create(-7);
   /*
          -10
          /\
        -9  -20
           /\
         -15  -7

         max path sum = 0

https://pages.cs.wisc.edu/~vernon/cs367/notes/8.TREES.html
    */
    ans = 0;
    maxPathSum(root3,&ans);
    printf("Max path sum : %d\n\n",ans);

    return 0;
}
