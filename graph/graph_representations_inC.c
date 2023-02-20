#include<stdio.h>
#include <stdlib.h>
#define MAX 100

struct NodeList{
    int value;
    struct NodeList* next;
};

void insertElement(struct NodeList** vertex, int v){
    struct NodeList* newNode, *temp;
    newNode = (struct NodeList*)malloc(sizeof(struct NodeList));
    newNode->value = v;
    newNode->next = NULL;
    temp = *vertex;
    if(temp == NULL){
        //1st connection recorded
        temp = newNode;
        return;
    }

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}

void adjacencyList(struct NodeList *graph[], int v1, int v2){
    //assume undirected graph
    //here we create an array of linked list
    insertElement(&graph[v1], v2);
    insertElement(&graph[v2], v1);
}


void adjacencyMatrix(int mat[][MAX],int v1, int v2){
    mat[v1][v2] = 1;
    mat[v2][v1] = 1;
}

void printmat(int mat[][MAX], int n){
    int i,j;
    for(i = 0; i <= n; i++){
        for(j = 0; j <= n; j++){
            if(i == 0  && j == 0) printf("     ");
            else if(i == 0) printf("v%-4d", j);
            else if(j == 0) printf("v%-4d", i);
            else printf("%-5d", mat[i][j]);
        }
        printf("\n");
    }
}

void printAdjacencyList(struct NodeList* graph[], int n){
    int i;
    struct NodeList* vertex;
    for(i = 1; i <= n; i++){
        printf("\nVertex %d :- [ ", i);
        vertex = graph[i];
        if(vertex != NULL) {

            do{
                printf("%d, ",vertex->value);
                vertex = vertex->next;
            }while(vertex->next != NULL);
        }
        printf(" ]");
    }
}

int main(){
    int v1,v2,n,i;
    int mat[MAX][MAX];
    struct NodeList* graph[MAX] = {NULL};
    printf("\nEnter no. of vertices : ");
    scanf("%d",&n);
    for (i = 1; i <= n; i++) {
        printf("\nEnter pair of vertices(1 to n) which are connected : ");
        scanf("%d %d", &v1, &v2);
        //assume undirected graph
        adjacencyMatrix(mat, v1, v2);
        adjacencyList(graph, v1, v2);
    }
    printmat(mat, n);
    printAdjacencyList(graph, n);
    return 0;
}




//ADJACENCY LIST TO BE DONE....

