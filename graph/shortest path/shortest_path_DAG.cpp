void toposort_dfs(int curnode, vector<int> &vis, vector<vector<pair<int,int>>> &adjlist, stack<int> &stk){
    vis[curnode] = 1;

    for(auto it : adjlist[curnode]){
        int adjnode = it.first;
        if(!vis[adjnode]) toposort_dfs(adjnode, vis, adjlist, stk);
    }

    stk.push(curnode);
}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    int V = n;
    vector<vector<pair<int, int>>> adjlist(V);
    for(auto edge : edges){
        int u = edge[0], v = edge[1], wt = edge[2];
        adjlist[u].push_back({v, wt});
    }

    //find toposort dfs
    //check for all components
    stack<int> stk;
    vector<int> vis(V, 0);
    for(int i = 0; i < V; i++){
        if(!vis[i]) toposort_dfs(i, vis, adjlist, stk);
    } 

    vector<int> dist(V, 1e9);
    dist[0] = 0; //we start at 0 so distance will always be 0
    while(!stk.empty()){
        int curnode = stk.top(); stk.pop();

        for(auto it : adjlist[curnode]){
            int adjnode = it.first, wt = it.second;
            if(dist[curnode] + wt < dist[adjnode]){
                dist[adjnode] = dist[curnode] + wt;
            }
        }
    }
    //if distance is 1e9 its theoretically too huge meaning not possible hence -1
    for(auto &d : dist){
        if(d == 1e9) d = -1;
    }
    return dist;

}
