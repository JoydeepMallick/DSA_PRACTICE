#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

//we need to construct queue data structure in order to use it in C programming
struct queue{
    int items[MAXSIZE];
    int front, rear;
};

struct queue* createQueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
int isEmpty(struct queue* q);
void printQueue(struct queue* q);

// nodes of a graph
struct node{
    int vertex;
    struct node *next;
};

struct node* createNode(int);

//graph data structure
struct Graph {
    int numVertices;
    struct node** adjList;
    int* visited;
};

struct Graph* createGraph(int vertices);
void addEdge(struct Graph *graph, int src, int dest);

struct queue* createQueue(){
    struct queue *q = malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

//check if queue is empty
int isEmpty(struct queue* q){
    if(q->rear == -1) return 1;
    else return 0;
}

//add elements to queue
void enqueue(struct queue* q, int value){
    if(q->rear ==MAXSIZE-1) printf("Queue is Full!!!");//we have surpassed static range of queue
    else{
        if(q->front == -1) q->front = 0;//if queue was empty intially then update front
        q->rear++;
        q->items[q->rear] = value;
    }
}

// removing elements from queue
int dequeue(struct queue* q){
    int item;
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        item = -1;
    }
    else{
        item = q->items[q->front];//store the front element
        q->front++;//update front to remove element
        if(q->front > q->rear){//queue has become empty
            printf("Resetting queue(since empty)\n");
            q->front = q->rear = -1; // again set it to start
        }
    }
    return item;//return removed element
}

//print the queue
void printQueue(struct queue* q){
    int i = q->front;
    if(isEmpty(q)){
        printf("Queue is empty!!!\n");
    }
    else{
        printf("front ->");
        for(i = q->front; i < q->rear+1; i++){
            printf("%3d", q->items[i]);
        }
        printf(" <- rear\n");
    }
}

//Functions related to creation of a graph
struct node* createNode(int v){
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices){
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjList = malloc(vertices * sizeof(struct node*));
    graph->visited = malloc(vertices * sizeof(int));
    int i = 0;
    for(i = 0; i < vertices; i++){
        graph->adjList[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}


void addEdge(struct Graph *graph, int src, int dest){
    // Add edge from src to dest
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}


void bfs(struct Graph* graph, int startVertex){
    struct queue* q = createQueue();
    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);

    while(!isEmpty(q)){
        printQueue(q);
        int currentVertex = dequeue(q);
        printf("Visited : %d\n ", currentVertex);

        struct node* temp = graph->adjList[currentVertex];
        //enqueue all the adjacents nodes of current removed vertex if not visited
        while(temp){
            int adjVertex = temp->vertex;
            if(graph->visited[adjVertex] == 0){
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}

int main(){
    int i;
    struct Graph* graph = createGraph(9);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 5, 6);
    addEdge(graph, 6, 7);
    addEdge(graph, 7, 8);
    addEdge(graph, 6, 8);
/*
             0----1------3       5-----6------7  
             |   / \    /               \     |
             |  /   \  /                 \    |
             | /     \/                   \   |
              2------4                     \  |
                                             8

 */
    //for disconnected components 
    for(i = 0; i < graph->numVertices; i++){
        if(graph->visited[i]==0) bfs(graph, i);
    }    
    /*
     bfs starts from 0 in above call

     answer -> 0 1 2 3 4 5 6 7 8    or    0 2 1 4 3 5 6 8 7   (varies) 
     */

    return 0;
}
