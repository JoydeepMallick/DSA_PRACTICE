#include <bits/stdc++.h>
using namespace std;

bool  dfs(int vertex, int colored[], int tocolor, vector<int> edgelist[]){
    //color uncolored vertex 
    colored[vertex] = tocolor;

    for(auto v : edgelist[vertex]){
        if(colored[vertex] == -1){//if uncolored 
            if(dfs(v, colored, !tocolor, edgelist) == false) return false;    
        }
        // if colored 
        if(colored[vertex] != tocolor) return false; 
    }

    return true;
}


bool isBipartite(int V, vector<int> edgelist[]){
    int colored[V+1] ;
    //intialize color graph 
    for(int i = 0; i < V+2; i++){
        colored[i] = -1;
    }
    // perform dfs and vertex color graph
    for(int vertex = 1; vertex <= V; vertex++){
        //for disconnected components if not colored 
        if(colored[vertex]==-1){
            if(dfs(vertex, colored, 0, edgelist) == false) return false;
        }
    } 
    return true;
}

int main(){
    vector<int> edgelist[] = {
        {},//1 based indexing so 0 is kept blank
        {2},
        {1,3,6},
        {2,4},
        {3,5,7},
        {4,6},
        {2,5},
        {4,8},
        {7},
    };

    int V = 8;
    cout << "\n\nBipartite graph : " << isBipartite(V, edgelist) <<endl;
    return 0;
}
