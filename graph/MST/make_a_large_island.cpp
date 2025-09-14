#include <bits/stdc++.h>

class DisjointSet
{

public:
    vector<int> parent, size;

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

class Solution
{
public:
    int largestIsland(vector<vector<int>> &grid)
    {
        // n x n binary grid
        int n = grid.size();
        // prepare a DS of 1s
        DisjointSet ds(n * n);
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (grid[r][c] == 0)
                    continue;

                int dr[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1};
                for (int i = 0; i < 4; i++)
                {
                    int nr = r + dr[i], nc = c + dc[i];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1)
                    {
                        int node = r * n + c;
                        int adjnode = nr * n + nc;
                        ds.unionBySize(node, adjnode);
                    }
                }
            }
        }

        // now traverse all 0s, try searching for adjacent lands and compute max answer
        int ans = 0;
        for (auto sz : ds.size)
        {
            ans = max(ans, sz);
        }

        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (grid[r][c] == 1)
                    continue;

                int dr[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1};
                set<int> unique_ulp;
                for (int i = 0; i < 4; i++)
                {
                    int nr = r + dr[i], nc = c + dc[i];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1)
                    {
                        int adjnode = nr * n + nc;
                        unique_ulp.insert(ds.findUPar(adjnode));
                    }
                }

                int tempans = 1; // that 0 was assumed to be converted to land
                for (auto ulp : unique_ulp)
                {
                    tempans += ds.size[ulp];
                }

                ans = max(ans, tempans);
            }
        }
        return ans;
    }
};