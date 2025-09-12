// problem : https://leetcode.com/problems/making-a-large-island/description/

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
