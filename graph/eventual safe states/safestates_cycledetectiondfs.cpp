#include <bits/stdc++.h>
using namespace std;

bool dfs(int v, vector<int> adj[], int vis[], int pathvis[], int isSafe[]){
    //mark it as both vis and path visited 
    vis[v] = 1;
    pathvis[v] = 1;
//intially isSafe[v] is 0 since we assume its unsafe 
    //traverse all adjacent nodes of v 
    for(auto it : adj[v]){
        if(!vis[it]){//if node has not yet been visited
            if(dfs(it, adj, vis, pathvis, isSafe) == true) return true;// surely unsafe node
        }
        else if(pathvis[it]) return true;// cycle detected since its path visited already surely unsafe 
    }

    //if it never returned true in above we can surely say that it does not have a cycle 
    isSafe[v] = 1;// its safe 
    pathvis[v] = 0;
    return false;// no cycle found

}

vector<int> safeStates(int V, vector<int> adj[]){
    int vis[V] = {0}, pathvis[V] = {0};
    int isSafe[V] = {0}; // accounts for all safe nodes
    vector<int> safeNodes;
    //traverse all nodes in case some nodes are unreachable in dfs similar to traversing all components in a graph 
    for(int i = 0; i < V; i++){
        dfs(i, adj, vis, pathvis, isSafe);
    }

    //traverse all nodes again to store safe nodes from check(check[i] = 1 represents index i is a safe node) in ascending order
    for(int i = 0; i < V; i++){
        if(isSafe[i]) safeNodes.push_back(i);
    }

    return safeNodes;
}

int main(){
    /*
     o based indexing 

     0 ------> 1 ------> 2 --------> 3 --------> 5
               ^                     |           |
               |                     |           |
               |                     |           |
               8                     4 --------> 6 ---------> 7
              / \ 
             /   \
            v     v 
            9 --> 10
            ^
            |
            |
            11 

            safe nodes = 0,1,2,3,4,5,6,7

*/
    int V = 12;

    vector<int> adj[] = {
        {1},
        {2},
        {3},
        {4,5},
        {6},
        {6},
        {7},
        {},
        {1,9},
        {10},
        {8},
        {9},
    };
    
    cout << "Safe states : ";
    for(auto ele : safeStates(V, adj)){
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}
