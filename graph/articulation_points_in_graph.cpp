#include <bits/stdc++.h>
using namespace std;

int timer = 0;
void dfs()
{
}

vector<int> findArticulationPoints(int V, int E, vector<vector<int>> &edgelist)
{
    // convert edgelist to adjacency list
    vector<vector<int>> adj(V);
    for (auto e : edgelist)
    {
        int u = e[0], v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(V, 0);
    vector<int> tin(V), low(V);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, vis, tin, low, mark, adj);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int edges = m;
        vector<vector<int>> edgelist;
        while (edges--)
        {
            int u, v;
            cin >> u >> v;
            edgelist.push_back({u, v});
        }
    }
    vector<int> AP = findArticulationPoints(n, m, edgelist);
    sort(AP.begin(), AP.end());

    for (auto points : AP)
    {
        cout << points << "\n";
    }
    return 0;
}