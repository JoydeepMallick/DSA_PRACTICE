// concept and template for disjoint sets
#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent;

public:
    // initialize all containers using constructor
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    // find ultimate parent of given node with path compression
    int findUPar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUPar(parent[node]); // this causes path compression along the search
    }

    // union by rank
    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return; // already in same set
    }
}