#include<stdio.h>

void Enqueue(int q[],int ele,int *front,int *rear,int *cap){
	if(*front == (*cap) - 1) printf("Overflow!");
	else{
        if(*rear == -1) ++(*front);
        q[++(*rear)] = ele;
    }
}

void Dequeue(int q[],int *front,int *rear){
    int i;
	if(*front == -1) printf("Underflow!");
	else {
        printf("%d removed from front.\n",q[(*front)]);
        if(--(*rear) > -1){
            //shift all elements by one position
            for(i = *front; i <= *rear; i++) q[i] = q[i+1]; 
        }
        else (*front) = -1;
    }
}

void display(int q[],int *front, int *rear){
	int i;
	if(*rear == -1){
		printf("\nEmpty queue!");
	}
	else{
		for(i = *front; i <= *rear; i++){
			printf("%d",q[i]);
			if(i == *front) printf("(front)");
			if(i == *rear) printf("(rear)");
			printf("\n");
		}
	}
	
}

/*
 *array is the following type

 indices 0  1  2  3  4  ...........
       front        rear

       hence if stack not empty then front is always 0 and rear goes on increasing.
       after dequeue every element is shifted by one position but when no element left again both front and rear set to -1
 */
int main(){
	int q[1000];//predefining an array of fixed size
	int front,rear;
	int capacity,ch;
	printf("Enter size of Queue : ");
	scanf("%d",&capacity);
	front = -1;
	rear = -1;
	while(1){
		printf("\n\n0. Exit\n1. Enquque\n2. Dequeue\n3. Display\nEnter your choice : ");
		scanf("%d",&ch);
        if(ch==0) break;
		switch(ch){
			case 1:
				printf("Enter element to add : ");
				scanf("%d",&ch);
				Enqueue(q,ch,&front,&rear,&capacity);
				break;
			case 2:
				Dequeue(q,&front,&rear);
				break;
			case 3:
				display(q,&front,&rear);
				break;
			default:
				printf("\nInvalid choice!!!\n");
		}
	}
	return 0;
}
