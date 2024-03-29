#include<stdio.h>

//a  linked list node
struct Node {
    int data;
    struct Node* next;
};
  
// This function prints contents of linked list starting from the given node
//traversing can be done when we pass head as parameter
void printList(struct Node* n){
    while (n != NULL) {
        printf("%d ---> ", n->data);
        n = n->next;
        if(n == NULL) printf("NULL\n\n");
    }
}

/* Given a reference (pointer to pointer) to the head of a list and 
   an int, inserts a new node on the front of the list. */
void push(struct Node** head_ref, int new_data){
    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    /* 2. put in the data  */
    new_node->data  = new_data;
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);
    /* 4. move the head to point to the new node */
    (*head_ref) = new_node;
}
  
/* Given a node prev_node, insert a new node after the given 
   prev_node */
void insertAfter(struct Node* prev_node, int new_data){
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL){
      printf("the given previous node cannot be NULL");
      return;
    }
    /* 2. allocate new node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    /* 3. put in the data  */
    new_node->data  = new_data;
    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;
    /* 5. move the next of prev_node as new_node */
    prev_node->next = new_node;
}
  
/* Given a reference (pointer to pointer) to the head
   of a list and an int, appends a new node at the end  */
void append(struct Node** head_ref, int new_data){
    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *head_ref;  /* used in step 5*/
    /* 2. put in the data  */
    new_node->data  = new_data;
    /* 3. This new node is going to be the last node, so make next of
          it as NULL*/
    new_node->next = NULL;
    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL){
       *head_ref = new_node;
       return;
    }
    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;
    /* 6. Change the next of last node */
    last->next = new_node;
    return;
}
  

int main(){
  /* Start with the empty list */
  struct Node* head = NULL;
  int ch,ele;
  while(1){
    printf("\n1. Insert an element to beginning" 
        "\n2. Insert an element to end"
        "\n3. Insert an element after a specific node(entered by user)"
        "\n4. Insert an element at a specific position"
        "\n5. To print the linked list from given node(Entered by user)"
        "\n6. Exit"
        "\nEnter your choice : ");
    scanf("%d",&ch);
    if(1<=ch && ch<=4) {
      printf("\nEnter element to be inserted : ");
      scanf("%d",&ele);
    }

    if(ch==1){
      push(&head,ele);
    }
    else if(ch==2){
      append(&head,ele);
    }
    else if(ch==5){
      printList(head);//traversing all elements
    }
    else if(ch==6) break;
    else printf("\n\nInvalid selection !!! Try again.\n\n");
  }
  return 0;
}
