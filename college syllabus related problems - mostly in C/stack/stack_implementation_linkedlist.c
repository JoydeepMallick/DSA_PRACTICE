#include<stdio.h>
#include<stdlib.h>

struct node{
	int val;
	struct node *next;
};

//pop is equivalent to remove element from end of linked LIST
struct node* pop(struct node **stack){
	struct node *tmp = *stack;
	struct node *prev;
	if(*stack == NULL){
		printf("Empty linkedlist!!!\n");
		return NULL;
	}
	else if(tmp->next == NULL){
		*stack = NULL;
		return tmp;
	}

	while(tmp->next != NULL){
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = NULL;
	return tmp;
}

void display(struct node *stack){
	struct node *tmp = stack;
	if(stack == NULL) printf("Empty stack!!!\n");
	else{
		while(tmp != NULL){
			if(tmp->next == NULL) printf("| %d <-- top\n\n",tmp->val);
			else printf("| %d |", tmp->val);
			tmp = tmp->next;
		}
	}
}

//append is equivalent to add element at end of linkedlist
void append(struct node **stack, int ele){
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	struct node *tmp = *stack;
	newnode->val = ele;
	newnode->next = NULL;
	if(*stack == NULL){
		*stack = newnode;
		return;
	}
	while(tmp->next != NULL) tmp = tmp->next;
	tmp->next = newnode;
}

int main(){
	struct node *stack = NULL;
	struct node *deletednode;
	display(stack);
	append(&stack, 23);
	append(&stack, 56);
	display(stack);
	deletednode = pop(&stack);
	printf("Deleted node : %d\n", deletednode->val);
	display(stack);
	return 0;
}
