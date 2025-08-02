int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    int N = n;
    // 1 based indexing
    vector<vector<int>> dist(N + 1, vector<int>(N + 1, 1e9)); // avoid int max to avoid overflow whill summation
    for (auto edge : edges)
    {
        int u = edge[0], v = edge[1], wt = edge[2];
        dist[u][v] = wt;
    }
    // setting same node to 0 avoids traversing self loop costs
    for (int i = 1; i <= N; i++)
    {
        dist[i][i] = 0;
    }

    for (int internode = 1; internode <= N; internode++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                // avoid if anyone is infinity (here 1e9 assumed)
                if (dist[i][internode] == 1e9 || dist[internode][j] == 1e9)
                    continue;
                dist[i][j] = min(dist[i][j], dist[i][internode] + dist[internode][j]);
            }
        }
    }

    // check for negative cycle
    for (int i = 1; i <= N; i++)
    {
        if (dist[i][i] < 0)
            std::cout << "Negative cycle detected" << std::endl;
    }

    return dist[src][dest];
}