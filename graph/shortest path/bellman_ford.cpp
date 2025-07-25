vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges)
{
    int V = n, E = m;
    vector<int> dist(V + 1, INT_MAX); // 1 based indexing
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++)
    {
        for (auto it : edges)
        {
            int u = it[0], v = it[1], wt = it[2];
            if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // check for negative cycle in Vth relaxation
    for (auto it : edges)
    {
        int u = it[0], v = it[1], wt = it[2];
        if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
        {
            // Negative cycle detected
            return {-1}; // or handle as needed
        }
    }

    return dist;
}