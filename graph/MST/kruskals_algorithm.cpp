class DisjointSet
{

    vector<int> size, parent;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
        size.resize(n + 1, 1);
    }

    int findUPar(int node)
    {
        if (parent[node] == node)
            return node;
        parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u), ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return; // same component
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

int kruskalMST(int n, vector<vector<int>> &edges)
{
    // edges are in fashion {u,v,wt}
    // sort edges by wt
    sort(edges.begin(), edges.end(), [](vector<int> edge1, vector<int> edge2)
         { return edge1[2] < edge2[2]; });

    DisjointSet ds(n);

    vector<vector<int>> MST;
    int cost = 0;
    for (auto edge : edges)
    {
        int u = edge[0], v = edge[1], wt = edge[2];
        if (ds.findUPar(u) != ds.findUPar(v))
        {
            ds.unionBySize(u, v);
            MST.push_back(edge);
            cost += wt;
        }
    }
    return cost;
}
