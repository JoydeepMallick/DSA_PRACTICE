// here the only crux in dijkstra is the go on searching even after reaching the destination
//  until the min value of priority queue is the destination location itself

class Solution
{
private:
    struct State
    {
        int eff, x, y;
        bool operator>(const State &other) const
        {
            return eff > other.eff;
        }
    };

public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int r = heights.size(), c = heights[0].size();
        vector<vector<int>> dist(r, vector<int>(c, INT_MAX));

        dist[0][0] = 0;
        priority_queue<State, vector<State>, greater<State>> minpq;

        minpq.push({0, 0, 0});

        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        while (!minpq.empty())
        {
            auto [eff, x, y] = minpq.top();
            minpq.pop();
            if (x == r - 1 && y == c - 1)
                return eff;

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (0 <= nx && nx < r && 0 <= ny && ny < c)
                {
                    int neweff = abs(heights[nx][ny] - heights[x][y]);
                    neweff = max(eff, neweff);
                    if (neweff < dist[nx][ny])
                    {
                        dist[nx][ny] = neweff;
                        minpq.push({neweff, nx, ny});
                    }
                }
            }
        }
        return -1; // this case will never be reached as dest always reachable
    }
};