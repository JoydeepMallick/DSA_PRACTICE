#include<stdio.h>
int front,rear,size;


void Enqueue(int q[],int ele,int size){
    if((rear == size-1 && front == 0) || rear == front-1) printf("\nCircular Queue is full!!!");//0 to end filled else rotated version filled
    else if(rear == size-1 && front!=0){//filed till end but from start few places empty
    else 
}

void Dequeue(int q[],int *front,int *rear){

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

int main(){
	int q[1000];//predefining an array of fixed size
	int size,ch;
	printf("Enter size of Queue : ");
	scanf("%d",&size);
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
				Enqueue(q,ch);
				break;
			case 2:
				Dequeue(q,front,rear);
				break;
			case 3:
				display(q,front,rear);
				break;
			default:
				printf("\nInvalid choice!!!\n");
		}
	}
	return 0;
}
