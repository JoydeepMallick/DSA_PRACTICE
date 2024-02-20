#include<stdio.h>
#include<stdlib.h>

struct node{
	int val;
	struct node *next;
};

/* my older version */
void enQueue(struct node **queue, int ele){
	//similar to appending at end of linked list
	struct node *tmp;
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->val = ele;
	newnode->next = NULL;
	if(*queue == NULL){
		*queue = newnode;
		return;
	}
	tmp = *queue;
	while(tmp->next != NULL) tmp = tmp->next;
	tmp->next = newnode;
}

int deQueue(struct node **queue){
	struct node *tmp = *queue;
	if(*queue == NULL) printf("Nothing to delete!!!\n\n");
	else{
		*queue = (*queue)->next;
		return tmp->val;
	}
}

void display(struct node *queue){
	struct node *tmp = queue;
	if(queue == NULL) printf("Empty Queue !\n\n");
	else{
		while(tmp != NULL){
			if(tmp == queue) printf("(front) -> ");
			printf("%4d |", tmp->val);
			if(tmp->next == NULL) printf(" <- rear\n\n"); 
			tmp = tmp->next;
		}
	}
}

/*updated version*/



int main(){
	int front, rear, size;
	struct node *queue;
	printf("Enter  the size of linear queue(press -1 to denote infinite) : ");//assume a fixed size linked list
	scanf("%d", &size);
	if(size == -1){
		queue = NULL;
		//no need of rear and front pointer                                                                                                                                                     
		enQueue(&queue,45);
		enQueue(&queue, 12);
		display(queue);
		printf("Element removed : %d\n\n", deQueue(&queue));
		display(queue);
	}
	return 0;
}
