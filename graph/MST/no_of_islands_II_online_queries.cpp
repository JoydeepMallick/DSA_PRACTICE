#include <bits/stdc++.h>

class DisjointSet
{
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        // initialize
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
        size.resize(n + 1, 1);
    }

    int findUPar(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u), ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        else if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q)
{

    // lambda function to calculate current node value based on coordinates
    auto nodeval = [&m](int x, int y)
    {
        return m * x + y;
    };

    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    int vis[n][m];
    memset(vis, 0, sizeof vis); // all water, represented as single vector

    DisjointSet ds(m * n);

    vector<int> ans;

    int cnt = 0;

    for (auto it : q)
    {
        int x = it[0], y = it[1];
        // if already visited no more checks needed
        if (vis[x][y] == 1)
        {
            ans.push_back(cnt);
            continue;
        }

        vis[x][y] = 1;
        cnt++; // assuming land is seperate as of now, below checks can remove this

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] == 1)
            {
                // if valid coordinate and land exists (meaning cell had been visited before)
                int curnode = nodeval(x, y);
                int adjnode = nodeval(nx, ny);
                // this ensures once curnode gets connected to set, other set elements even if encountered are not reconnected
                if (ds.findUPar(curnode) != ds.findUPar(adjnode))
                {
                    // yet to be connected as single island
                    cnt--;
                    ds.unionBySize(curnode, adjnode);
                }
            }
        }
        ans.push_back(cnt);
    }

    return ans;
}