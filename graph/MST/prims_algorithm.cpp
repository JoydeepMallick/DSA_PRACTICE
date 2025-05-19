#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // {{u, v}, wt }
    vector<pair<pair<int, int>, int>> MST;
    int V = n, E = m;
    vector<vector<vector<int>>> adj(V+1);//1 based indexing
    for(auto edge : g){
        int u = edge.first.first, v = edge.first.second;
        int wt = edge.second;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    //start from arbitrary node;
    //pq contains {wt, node, parent} as we need to store MST
    priority_queue<vector<int>, 
    vector<vector<int>>, greater<vector<int>> > pq;

    pq.push({0,1, -1});//start at 1, no edge weight and parent
    vector<int> vis(V+1, 0);
    int s = 0;

    while(!pq.empty()){
        int node = pq.top()[1], parent = pq.top()[2];
        int wt = pq.top()[0];
        pq.pop();

        if(vis[node]) continue;//skip
        //add it to MST
        vis[node] = 1;
        s += wt;
        if(parent != -1){
            MST.push_back({{node, parent}, wt});
        }

        for(auto it : adj[node]){
            int adjnode = it[0], edgeW = it[1];
            if(!vis[adjnode]){
                pq.push({edgeW, adjnode, node});
            }
        }
    }
    //total sum is s
    return MST;

}
