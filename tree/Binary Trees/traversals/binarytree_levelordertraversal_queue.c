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



//level order traversal
void printLevelOrder(struct node *root){
    int rear,front;
    struct node** queue = createQueue(&front,&rear);//front and rear updated
    struct node *tempnode = root;
    while(tempnode){
        printf("%d ",tempnode->data);
        //enqueue left child
        if(tempnode->left) enQueue(queue, &rear, tempnode->left);
        //enqueue right child
        if(tempnode->right) enQueue(queue, &rear, tempnode->right);
        //dequeue node and make it tempnode
        tempnode = deQueue(queue, &front);
    }
}

/*
 * above code works as follows for assumed tree
 *
 * in the queue following occurs
 * print 1
 * 2 3
 * pop 2
 * 3 4 5
 * print 2
 * pop 3
 * 4 5 6 7
 * print 3
 * (no more enqueue as no more children only deque)
 * print 4
 * print 5
 * print 6
 * print 7
 */


struct node* Create(int ele){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = ele;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

int main(){
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

    printf("Level order traversal using queue : ");
    printLevelOrder(root);
    return 0;
}
