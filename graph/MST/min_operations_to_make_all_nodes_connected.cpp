// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

class DisjointSet
{
public:
    vector<int> rank, parent, size;

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
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        DisjointSet ds(n);
        int extraedgecnt = 0;
        for (auto edge : connections)
        {
            if (ds.findUPar(edge[0]) != ds.findUPar(edge[1]))
            {
                ds.unionBySize(edge[0], edge[1]);
            }
            else
            {
                // already connected hence extra edge, can be detached and reused
                extraedgecnt++;
            }
        }

        // count no. of min operations needed to connect all
        int totalcomponents = 0;
        for (int node = 0; node < n; node++)
        {
            if (ds.findUPar(node) == node)
                totalcomponents++;
        }

        int minsteps = totalcomponents - 1;

        if (extraedgecnt >= minsteps)
            return minsteps;
        else
            return -1;
    }
};