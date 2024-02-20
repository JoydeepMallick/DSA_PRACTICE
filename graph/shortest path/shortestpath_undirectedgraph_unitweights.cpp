#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int V, int E, int src, vector<vector<int>> &edges){
    //create a adjacency list 
    vector<int> adj[V];
    for(auto it : edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    int dist[V];
    for(int i = 0; i < V; i++){
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto nb : adj[node]){
            if(dist[node] + 1 < dist[nb]){
                dist[nb] = dist[node]+1;
                q.push(nb);
            }
        }
    }
    vector<int> ans(V, -1);
    for(int i = 0; i < V; i++){
        if(dist[i] != INT_MAX) ans[i] = dist[i];
    }

    return ans;
}

int main(){
    vector<vector<int>> edges = {//weight of each edge is 1
        {0,1},
        {0,3},
        {1,2},
        {1,3},
        {2,6},
        {3,4},
        {4,5},
        {5,6},
        {6,7},
        {6,8},
        {7,8},
    };
    /*
            
                       1 --------- 2       7 
                      /|            \     / \
                     / |             \   /   \
                    /  |              \ /     \
                   0---3----4----5-----6 ----- 8 
     */

    int V = 9, E = 11, src;
    cout << "Enter source(0 till 9) : ";
    cin >> src;
    cout << "Shortes path from source " << src << " : [";
    for(auto it : shortestPath(V,E,src,edges)){
        cout << it << ", ";
    }
    cout << "\b\b]\n";
    return 0;
}
