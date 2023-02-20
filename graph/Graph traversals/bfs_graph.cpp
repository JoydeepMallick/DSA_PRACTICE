#include <bits/stdc++.h>
using namespace std;

//we are given a source node and a adjacency list for the graph
vector<int> bfs_ofgraph(int no_of_V, int source, vector<int> adj[]){
    int visited[no_of_V+1] = {0};//we assume 1 based indexing
    visited[source] =  1;
    queue<int> q;
    q.push(source);//queue has function push and pop like stack
    vector<int> bfs;
    while(!q.empty()){
        int node = q.front();
        q.pop();//pop front of queue
        bfs.push_back(node);
        for(auto it : adj[node]){
            //for each element in queue visit its connected nodes and store them in queue if not visited
            if(!visited[it]){
                visited[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}


void print_bfs(int size, int source, vector<int> adj[]){
    vector<int> bfs = bfs_ofgraph(size, source,adj);
    cout << "\nBFS Graph traversal when source is " << source << " :- ";
    for(auto it : bfs){
        cout << it << " ";
    }
    cout << "\n\n";
}

void printadj(vector<int> adj[], int size){
    for(int i = 1; i <= size; i++){
        cout << "Vertex " << i << " :- { ";
        for(auto it : adj[i]){
            cout << it << " ";
        }
        cout << " }\n";
    }
}

int main(){
    int n;
    /* cout << "Enter no. of vertices : "; */
    /* cin >> n; */
    n = 8;
    vector<int> adj[n+1] = {{}, {2,6}, {1,3,4}, {2}, {2,5}, {4,7}, {1,7,8}, {5,6}, {6}};
    /*
       assume the following graph

           1
         /  \
       2    6
     / \   / \
   3   4  7   8
       \ /
       5
    */
    printadj(adj, n);
/* int source; */
/* cout << "Enter source : "; */
/* cin >> source; */
    for(int i = 1; i <= n; i++)
        print_bfs(n, i, adj);
    return 0;
}


//code is valid only when all components are connected
//
//for disconnected components 
//
//https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
