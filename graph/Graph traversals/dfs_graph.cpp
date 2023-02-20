#include <bits/stdc++.h>
using namespace std;

void printadj(vector<int> adj[], int size){
    for(int i = 1; i <= size; i++){
        cout << "Vertex " << i << " :- { ";
        for(auto it : adj[i]){
            cout << it << " ";
        }
        cout << " }\n";
    }
}

void dfs_of_graph(vector<int> adj[], int node, map<int, bool> &visited){
    //mark as visited
    visited[node] = true;
    //print it
    cout << node << " ";
    //before dfs on all its connected components, this might fail if there are disconnected components hence updates needed
    for(auto it : adj[node]){
        if(!visited[it])
            dfs_of_graph(adj, it, visited);
    }
}

void print_dfs(int n, int source, vector<int> adj[]){
    map<int, bool> visited;
    dfs_of_graph(adj, source, visited);
    
}

int main(){
    int n;
    /* cout << "Enter no. of vertices : "; */
    /* cin >> n; */
    n = 8;
    vector<int> adj[n+1] = {{}, {2,3}, {1,5,6}, {1,4,7}, {3,8}, {2}, {2}, {3,8}, {4,7}};
    /*
       assume the following graph

           1
         /  \
       2    3 -- 4
     / \   /    /
   5   6  7 __ 8
       
    */
    cout << "Entered  adjacency matrix :- ";
    printadj(adj, n);
/* int source; */
/* cout << "Enter source : "; */
/* cin >> source; */
    //for each source node we print dfs
    cout << "this code is limited to connected graph : -\n\n";
    for(int i = 1; i <= n; i++)
    {
        cout << "When source node is "<< i << " :-   ";
        print_dfs(n, i, adj);
        cout << "\n";
    }
    return 0;
}


//code is valid only when all components are connected
