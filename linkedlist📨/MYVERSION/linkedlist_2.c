#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node *next;
};

struct node* createlist(struct node *head){
    int n,d;
    struct node *newnode,*ptr;
    printf("\n\nHow many elements to enter : ");
    scanf("%d",&n);
    ptr = head;//useful when linkedlist has some nodes already else its updated within program
    while(n--){
        //create a new node of same size as struct node
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data : ");
        scanf("%d",&d);
        newnode->data = d;
        newnode->next = NULL;//null stored

        if(head == NULL) {
            head = newnode;//if head was NULL ie. it had no node initially create head as a node first
            ptr = head;//now we need to move further adding nodes to the head
                       //so we use a ptr to head to do the same(storing ptr as head earlier meant storing NULL for NUll head & loc for linkedlist)
        }
        else{
            //reach to end to linked list starting from node head
            while(ptr->next != NULL) ptr = ptr->next;
            //connect newnode to end of original linked list at end
            ptr->next = newnode;
        }
        //printlist(head);
    }
    return head;
}

void printlist(struct node *head){
    struct node* ptr; 
    ptr = head;//head denotes start of linked list
    if(head == NULL) {
        printf("\n\nStarting address : NULL");//no node to display
        return;
    }
    else printf("\n\nStarting address : %p --->",ptr);

    while(ptr->next != NULL){
        printf("|%d|%p| ---> ",ptr->data,ptr->next);
        ptr = ptr->next;
    }
    if(ptr->next == NULL) printf("|%d|NULL| ",ptr->data);//the last missed node due to loop breaking at that point
}

_Bool search(int ele,struct node *head){
    struct node * ptr;
    if(head == NULL) return false;//no node present to search
    else{
        ptr = head;
        while(ptr->next != NULL){
            if(ptr->data == ele) return true;
            ptr = ptr->next;
        }
        if(ptr->data == ele) return true;//the last unchecked node
        else return false;
    }
}

int main(){
    struct node *head = NULL;
    _Bool found;
    int ele;
    printlist(head);
    head = createlist(head);
    printlist(head);
    printf("\n\nEnter element to be searched : ");
    scanf("%d",&ele);
    found = search(ele,head);
    printf("\n%d is %s found\n",ele,found?"":" not ");
    return 0;
}
