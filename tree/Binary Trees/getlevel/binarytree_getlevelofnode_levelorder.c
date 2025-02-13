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

int getLevel(struct node *root, int ele){
    int front,rear,size;
    if(root == NULL){
        return -1;
    }
    //else perform level order traversal till either left child or right
    //child is found NULL
    struct node **queue = createQueue(&front,&rear);//initializing and creating queue
    struct node *tempnode;
    //enQueue(queue,&rear,root);//no need to enqueue root else loop would run one more time in dequeue 
    int currentlevel = 0;//intially assumed root
    tempnode = root;
    
    //initially queue is empty hence we push root
    enQueue(queue,&rear,tempnode);
    //hence front is 0 and rear is 1

    while(rear - front){//while queue is not empty
        size = rear - front;
        while(size--){ 
            tempnode = deQueue(queue,&front);//front gets updated
            if(tempnode->data == ele) return currentlevel;

            if(tempnode->left) enQueue(queue,&rear,tempnode->left);
            if(tempnode->right) enQueue(queue,&rear,tempnode->right);
        }
        currentlevel++;//entered next level
    }
    //if not found
    return -1;
}

int main(){
    int ele;
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
    printf("\n\nAll the node levels are printed below(-1 means node element doesn't exist) :-\n\n");
    for(ele = 0; ele <= 10; ele++){
        printf("Level of %d : %d\n",ele,getLevel(root,ele));
    }

    return 0;
}
