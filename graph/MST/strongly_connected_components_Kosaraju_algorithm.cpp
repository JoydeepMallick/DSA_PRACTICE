#include <bits/stdc++.h>

void dfs_finishing_time(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &stk)
{
    vis[node] = 1;
    for (auto adjnode : adj[node])
    {
        if (!vis[adjnode])
            dfs_finishing_time(adjnode, vis, adj, stk);
    }
    stk.push(node);
}

void dfs(int node, vector<int> &vis, vector<vector<int>> &adj)
{
    vis[node] = 1;
    for (auto adjnode : adj[node])
    {
        if (!vis[adjnode])
            dfs(adjnode, vis, adj);
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    // convert graph from edgelist to adjacency list for use
    vector<vector<int>> adj(v);
    for (auto ed : edges)
    {
        int u = ed[0], v = ed[1];
        adj[u].push_back(v);
    }

    // step 1 : sort in order of max finish time on top
    vector<int> vis(v, 0);
    stack<int> stk;

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
            dfs_finishing_time(i, vis, adj, stk);
    }

    // step 2 : reverse all edges, transpose of graph
    vector<vector<int>> adjTr(v);
    for (auto ed : edges)
    {
        int u = ed[0], v = ed[1];
        adjTr[v].push_back(u);
    }

    // step 3 : reseting visited array since we are gonna reuse it again
    fill(vis.begin(), vis.end(), 0);

    // step 4: traverse stack in order and get SCC
    int scc_cnt = 0;
    while (!stk.empty())
    {
        int node = stk.top();
        stk.pop();
        if (!vis[node])
        {
            dfs(node, vis, adjTr);
            scc_cnt++;
        }
    }
    return scc_cnt;
}