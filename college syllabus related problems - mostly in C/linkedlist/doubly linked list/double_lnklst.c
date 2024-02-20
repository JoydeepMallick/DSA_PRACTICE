#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *prev;
	int data;
	struct node *next;
};

void display(struct node *head){
	struct node *ptr = head;
	if(head == NULL) printf("\nHead : NULL");
	else{
		printf("\nHead : %p -->",head);
		while(ptr->next != NULL){
			printf("| %p | %d | %p | -->",ptr->prev,ptr->data,ptr->next);
			ptr = ptr->next;
		}
		printf("| %p | %d | %p |",ptr->prev,ptr->data,ptr->next);
	}
}

void insertatend(struct node **head,int ele){
	struct node *ptr,*newnode;
	newnode = (struct node*)(malloc(sizeof(struct node)));
	newnode->data = ele;
	newnode->next = NULL;
	if(*head == NULL) {
		*head = newnode;
		newnode->prev = NULL;
	}
	else{
		ptr = *head;
		while(ptr->next != NULL) ptr = ptr->next;
		newnode->prev = ptr;
		ptr->next = newnode;
	}
}

void insertatstart(struct node **head,int ele){
	struct node *newnode;
	newnode = (struct node*)(malloc(sizeof(struct node)));
	newnode->data = ele;
	newnode->prev = NULL;
	if(*head == NULL) {
		newnode->next = NULL;
		*head = newnode;
	}
	else{
		newnode->next = *head;
		(*head)->prev = newnode;
		*head = newnode;
	}
}

void deletefromend(struct node **head){
	struct node *ptr = *head;
	if(*head == NULL) printf("\nNothing to delete!!!");
	else if((*head)->next == NULL) {
		*head = NULL;
		free(ptr);
	}
	else{
		while(ptr->next != NULL) ptr = ptr->next;
		ptr->prev->next = NULL;
		free(ptr);
	}
}

void deletefromstart(struct node **head){
	struct node *ptr = *head;
	if(*head == NULL) printf("\nNothing to delete!!!");
	else if((*head)->next == NULL) {
		*head = NULL;
		free(ptr);
	}
	else{
		(*head)->next->prev = NULL;
		(*head)=(*head)->next;
		free(ptr);
	}
}

int main(){
	int ch,ele;
	struct node *start = NULL;
	while(1){
		printf("\n\n0. Exit\n1. Insert at start\n2. Insert at end\n3. Display\n4. Delete from start\n5. Delete from end\nEnter your choice : ");
		scanf("%d",&ch);
		if(ch==0) break;
		else if(ch==1 || ch==2){
			printf("\nEnter element : ");
			scanf("%d",&ele);
			(ch==1)?insertatstart(&start,ele) : insertatend(&start,ele);
		}
		else if(ch==3) display(start);
        else if(ch==4) deletefromstart(&start);
        else if(ch==5) deletefromend(&start);
        // else if(ch==6){
        //     printf("\nEnter element to search : ");
        //     scanf("%d",&ele);
        //     if(search(start,ele)) printf("\n%d found in circular list.\n",ele);
        //     else printf("\nSorry!!! number not found.\n");
        // }
        else printf("\nWrong choice!!!\n");
	}

	return 0;
}
