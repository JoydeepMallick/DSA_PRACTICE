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

int main()
{
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    cout << "1 and 5 are in the same set: " << (ds.findUPar(1) == ds.findUPar(5)) << endl;
    cout << "1 and 3 are in the same set: " << (ds.findUPar(1) == ds.findUPar(3)) << endl;

    ds.unionByRank(3, 4);
    cout << "1 and 5 are in the same set: " << (ds.findUPar(1) == ds.findUPar(5)) << endl;
    cout << "2 and 6 are in the same set: " << (ds.findUPar(2) == ds.findUPar(6)) << endl;
    cout << "3 and 7 are in the same set: " << (ds.findUPar(3) == ds.findUPar(7)) << endl;
}