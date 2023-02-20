#include<bits/stdc++.h>
using namespace std;


//will work if compiled with c99 standard else define with some constant

void adjacencyMatrix(int v1, int v2, vector<vector<int>> mat){
    mat[v1][v2] = 1;
    mat[v2][v1] = 1;

    //in case of weights in edges replace 1 by weights
}

void printmat(int n, vector<vector<int>> mat){
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

void adjacencyList(vector<int> adj[], int v1, int v2){
    //for undirected graph
    if(v1!=v2){
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
        //for weighted edges insert pair{vertex, edgeweight} for each
    }
    //for self loops
    else adj[v1].push_back(v1);
}

void printadj(vector<int> adj[], int size){
    for(int i = 1; i <= size; i++){
        cout << "Vertex " << i << " : - { ";
        for(auto it : adj[i]){
            cout << it << " ";
        }
        cout << " }\n";
    }
}

int main(){
    int v1,v2,i,size;
    printf("\nEnter no. of vertices : ");
    scanf("%d",&size);
    /*
       We create a 2D vector containing "n"
       elements each having the value "vector<int> (m, 0)".
       "vector<int> (m, 0)" means a vector having "m"
       elements each of value "0".
       Here these elements are vectors.
       */
    vector<vector<int>> mat(size, vector<int>(size, 0));//set all to 0
    vector<int> adj[size+1];
    for (i = 1; i <= size; i++) {
        printf("\nEnter pair of vertices(1 to n) which are connected : ");
        scanf("%d %d", &v1, &v2);
        //assume undirected graph
        /* adjacencyMatrix(v1, v2, mat); */
        adjacencyList(adj, v1, v2);
    }
    /* printmat(size, mat); */
    printadj(adj, size);
    return 0;
}




//MATRIX TO BE DONE....

