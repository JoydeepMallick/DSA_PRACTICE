// here the trick is to give priority to stops over distance.

class Solution
{

public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        // adjacency list creation
        vector<vector<array<int, 2>>> adj(n); // u---->{v, price}
        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        int cost[n];
        fill(cost, cost + n, INT_MAX);
        cost[src] = 0;

        queue<array<int, 3>> q;
        q.push({0, src, 0}); // { stops, node, cost[node] }

        while (!q.empty())
        {
            auto [stops, node, c] = q.front();
            q.pop();

            if (stops == k + 1)
                continue; // k stops consumated no more allowed

            for (auto it : adj[node])
            {
                int adjnode = it[0], price = it[1];
                // we are sure stops <= k
                if (c + price < cost[adjnode])
                {
                    cost[adjnode] = c + price;
                    q.push({stops + 1, adjnode, cost[adjnode]});
                }
            }
        }

        return (cost[dst] == INT_MAX) ? -1 : cost[dst];
    }
};