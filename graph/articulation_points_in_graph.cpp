#include <bits/stdc++.h>
using namespace std;

int timer = 0;

void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, vector<int> &markAP, vector<vector<int>> &adj) {
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    int childCount = 0;

    for (auto it : adj[node]) {
        if (it == parent) continue;
        if (!vis[it]) {
            dfs(it, node, vis, tin, low, markAP, adj);
            low[node] = min(low[node], low[it]);
            childCount++;

            if (low[it] >= tin[node] && parent != -1) {
                markAP[node] = 1;
            }
        } else {
            low[node] = min(low[node], tin[it]);
        }
    }

    if (parent == -1 && childCount > 1) {
        markAP[node] = 1;
    }
}

vector<int> findArticulationPoints(int V, int E, vector<vector<int>> &edgelist) {
    vector<vector<int>> adj(V);
    for (auto e : edgelist) {
        int u = e[0], v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(V, 0), tin(V), low(V), markAP(V, 0);

    for (int i = 0; i < V; i++) {
        if (!vis[i]) dfs(i, -1, vis, tin, low, markAP, adj);
    }

    vector<int> ans;
    for (int i = 0; i < V; i++) {
        if (markAP[i]) ans.push_back(i);
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edgelist;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--; // convert to 0-based
            edgelist.push_back({u, v});
        }

        vector<int> AP = findArticulationPoints(n, m, edgelist);
        sort(AP.begin(), AP.end());

        for (auto points : AP) cout << points + 1 << " "; // print 1-indexed
        cout << "\n";
    }

    return 0;
}
