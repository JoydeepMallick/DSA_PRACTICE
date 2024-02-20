#include <bits/stdc++.h>
using namespace std;

void dfs(int v, int vis[], vector<pair<int, int>> adj[], stack<int> &stk){
    vis[v] = 1;
    for(auto it : adj[v]){
        int node = it.first;
        if(!vis[node]) dfs(node, vis, adj, stk);
    }

    stk.push(v);
}

vector<int> shortestPath(int V, int E, int src , vector<int> edges[]){
    vector<pair<int, int>> adj[V];// creating a adjacency list
    for(int i = 0; i < E; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back(make_pair(v,wt));
    }

    //find toposort 
    int vis[V] = {0};
    stack<int> stk;
    for(int i = 0; i < V; i++){
        if(!vis[i]) dfs(i,vis, adj, stk);
    }

    //after building the stack intialize the distance array
    vector<int> dist(V);
    for(int i = 0; i < V; i++){
        dist[i] = 1e9;// reason not to set INT_MAX because INT_MAX + some number will exceed range of int and lead to incorrect reuslt
    }
    dist[src] = 0;

    //use the stack to build the distance array 
    while(!stk.empty()){
        int node = stk.top();
        stk.pop();

        for(auto nb : adj[node]){
            int v = nb.first;
            int wt = nb.second;
            if(dist[node] + wt < dist[v]){
                dist[v] = dist[node] + wt;
                /* 
                            wt 
                     node -----> v

                     to travel from src till node,  dist[node] is needed and from node till v , wt is needed. 
                     we will choose node as our internmediate only when it gives us a better result.
                */
            }
        }
    }
    return dist;
}

int main(){
    vector<int> edges[] = {// list of {starting edge, ending edge, edge weight}
        {6,4,2},
        {6,5,3},
        {5,4,1},
        {4,0,3},
        {4,2,1},
        {0,1,2},
        {1,3,1},
        {2,3,3},
    };
    /*
                  2            3            2            1
             6-----------> 4 ---------> 0 --------> 1 ----------> 3
              \           ^ \                                     ^ 
               \         /   \                                   /
                \       /     \                                 /
               3 \     /1     1\                               /
                  \   /         \                             / 3
                   V /           V                           /
                    5            2 --------------------------
     */

    int V = 7, E = 8, src ;
    cout << "Enter source node (0 till 6): ";
    cin >> src; 
    cout << "Shortest distance from source " << src << " is [ ";
    for(auto d : shortestPath(V, E, src, edges)){
        if(d==1e9) cout << "INF";
        else cout << d;
        cout << ", ";
    }
    cout << "\b\b ]\n";
    return 0;
}
