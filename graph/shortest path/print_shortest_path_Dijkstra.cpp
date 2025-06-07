#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &edges, int V, int E, int source, int dest) {
    // Create an adjacency list from the edges
    // u --> {v, wt}
    vector<vector<pair<int, int>>> adjlist(V);
    for(auto edge : edges){
        int u = edge[0], v = edge[1], wt = edge[2];
        adjlist[u].push_back({v, wt});
        adjlist[v].push_back({u, wt});
    }

    vector<int> dist(V, INT_MAX);
    vector<int> parent(V);
    for(int i = 0; i < V; i++) {
        parent[i] = i; // Initialize parent to itself
    }
    dist[source] = 0;
    parent[source] = -1; // Source has no parent


    //pair of {min distance to reach node, node}
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

    pq.push({0, source});

    while(!pq.empty()){
        int d = pq.top().first, node = pq.top().second;
        pq.pop();

        for(auto it : adjlist[node]){
            int wt = it.second, adjnode = it.first; 
            int newd = d + wt;
            if(dist[adjnode] > newd){
                dist[adjnode] = newd;
                parent[adjnode] = node; // Update parent to the current node
                pq.push({dist[adjnode], adjnode});
            }
        }
    }

    //for given destination, print the path
    vector<int> path;

    if(dist[dest] == INT_MAX) {
        return {}; // No path exists
    }
    int cur = dest;
    while(cur != -1) {//while cur has no parent meaning reached source
        path.push_back(cur);
        cur = parent[cur];
    }
    reverse(path.begin(), path.end()); // Reverse to get the path from source to destination
    return path;
}


//TC : O(ElogV) where E is the number of edges and V is the number of vertices
//SC : O(V) for the distance array and O(E) for the adjacency list
//Note : The graph is undirected and the edges are non-negative