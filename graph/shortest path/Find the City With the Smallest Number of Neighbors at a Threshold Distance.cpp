// problem link : https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/

class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        // initial configuration
        for (auto edge : edges)
        {
            int from = edge[0], to = edge[1], wt = edge[2];
            dist[to][from] = wt;
            dist[from][to] = wt;
        }
        // to avoid self loop costs if any
        for (int i = 0; i < n; i++)
        {
            dist[i][i] = 0;
        }

        // use floyd warshall

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                        continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int mincitycnt = n;  // worst possible
        int desiredcity = 0; // assume first one is desired
        for (int i = 0; i < n; i++)
        {
            int cntcity = 0;
            for (int j = 0; j < n; j++)
            {
                if (dist[i][j] <= distanceThreshold)
                    cntcity++;
            }
            if (cntcity <= mincitycnt)
            {
                mincitycnt = cntcity;
                desiredcity = i;
            }
        }

        return desiredcity;
    }
};