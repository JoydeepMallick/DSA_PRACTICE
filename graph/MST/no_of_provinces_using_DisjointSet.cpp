// concept and template for disjoint sets
#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;

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
        size.resize(n + 1, 1); // size of each set is initially 1
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

        // smaller ranked node gets attached to larger ranked node, meaning larger ranked node is parent of larger ranked node
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            // both ranks equal so any one can attach to other, rank increment happens
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++; // larger ones height increase
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return; // already in same set
        // smaller sized component joins larger one
        if (size[ulp_u] < size[ulp_v])
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
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        // create a edge list based on isConnected
        vector<vector<int>> edges; // 1 based indexing for nodes followed
        int n = isConnected.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j && isConnected[i][j])
                    edges.push_back({i + 1, j + 1});
            }
        }

        // now lets find connected components by Disjoint set and count each such seperate section
        DisjointSet ds(n);
        for (auto e : edges)
        {
            int u = e[0], v = e[1];
            if (ds.findUPar(u) != ds.findUPar(v))
            {
                // connect them
                ds.unionBySize(u, v);
            }
        }

        // our disjoint set with all disconnected components is constructed
        // lets store all the unique Ultimate parents which represent as leader of each component the count is out answer
        set<int> component_leaders;
        for (int node = 1; node <= n; node++)
        {
            component_leaders.insert(ds.findUPar(node));
        }

        return component_leaders.size();
    }
};