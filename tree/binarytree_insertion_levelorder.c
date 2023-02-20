#include<stdio.h>
#include<stdlib.h>
#define MAX_Q_SIZE 500

struct node{
    int data;
    struct node *left, *right;
};


//utility functions for implementation of queue
struct node **createQueue(int *front, int *rear){
    struct node ** queue = (struct node **)malloc(sizeof(struct node *)* MAX_Q_SIZE);
    //define a queue of fixed size 500
    *front = *rear = 0;
    return queue;//return pointer to queue which itself is a pointer to
                 //addresses
}

void enQueue(struct node **queue, int * rear, struct node *newnode){
    queue[*rear] = newnode;//pushing the newnode to rear end of queue
    (*rear)++;
}

struct node* deQueue(struct node **queue, int *front){
    (*front)++;//updating front of queue
    return queue[*front - 1];//pop the node and return to caller function

}

struct node* Create(int ele){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = ele;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}


struct node * InsertNode(struct node *root, int data){
    int front,rear;
    //if tree is empty assign a newnode
    if(root == NULL){
        root = Create(data);
        return root;
    }
    //else perform level order traversal till either left child or right
    //child is found NULL
    struct node **queue = createQueue(&front,&rear);//initializing and creating queue
    struct node *tempnode;
    //enQueue(queue,&rear,root);//no need to enqueue root else loop would run one more time in dequeue 

    tempnode = root;
    while(tempnode){
        if(tempnode->left) enQueue(queue,&rear,tempnode->left);
        else{
            //if null
            tempnode->left = Create(data);
            return root;
        }
        if(tempnode->right) enQueue(queue,&rear,tempnode->right);
        else{
            //if null
            tempnode->right = Create(data);
            return root;
        }

        tempnode = deQueue(queue,&front);//front gets updated
    }
}

//inorder traversal of binary tree
void inorder(struct node *Node){
    if(Node == NULL) return;
    else{
        inorder(Node->left);
        printf("%d ",Node->data);
        inorder(Node->right);
    }
}


int main(){
    int key;
    struct node* root = Create(1) ;
    root->left = Create(2);
    root->left->left = Create(4);
    root->left->right = Create(5);
    root->right = Create(3);
    root->right->left = Create(6);
    root->right->right = Create(7);
    /*
             1
            / \
           2   3
          /\   /\
         4 5  6  7
     */

    printf("\nInorder traversal before insertion : ");
    inorder(root);
    key = 45;
    root = InsertNode(root,key);//inserts 12 at suitable position
    root = InsertNode(root,56);
    root = InsertNode(root,12);
    printf("\n\nInorder traversal after insertion : ");
    inorder(root);
    /*
             1         <--- level 0
            / \          
           2   3         <--- level 1
          /\   /\         
         4 5  6  7         <--- level 2
       /\  /
    45 56 12                <--- level 4

    Insertion occurs in level order format i.e. highest level is completely filled from left to right before it jumps to next level. 
     */


    return 0;
}
