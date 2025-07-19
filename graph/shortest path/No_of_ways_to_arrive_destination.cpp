class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (auto r : roads)
        {
            int u = r[0], v = r[1], time = r[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq; // {time, node}
        pq.push({0, 0});

        vector<long long> totaltime(n, LLONG_MAX);
        totaltime[0] = 0;

        vector<long long> ways(n, 0);
        ways[0] = 1; // total ways to reach start is always 1

        const int mod = 1e9 + 7;

        while (!pq.empty())
        {
            auto [time, node] = pq.top();
            pq.pop();
            if (time > totaltime[node])
                continue; // skip uneeded path

            for (auto it : adj[node])
            {
                auto [adjnode, t] = it;
                if (time + t < totaltime[adjnode])
                {
                    totaltime[adjnode] = time + t;
                    ways[adjnode] = ways[node];
                    pq.push({totaltime[adjnode], adjnode});
                }
                else if (time + t == totaltime[adjnode])
                {
                    ways[adjnode] = (ways[adjnode] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1];
    }
};