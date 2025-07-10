
// Here 0 is the path and 1 is the obstacle
//  also the movement is allowed in 8 directions
//  the distance is calculated in terms of number of nodes traversed
//  so if the path is 0->1->2->3 then the distance is 4
//  [[0]] means answer is 1
//  [[1,0], [0, 0]] means answer is -1 as we cannot move from 1 to 0.

// source is always (0,0) and destination is always (n-1, m-1)

class Solution
{
private:
    struct State
    {
        int d, x, y;
    };

public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        const int r = grid.size(), c = grid[0].size();
        int dist[r][c];
        // initilize all dist array
        fill(&dist[0][0], &dist[0][0] + r * c, INT_MAX);

        int sourceX = 0, sourceY = 0, destX = r - 1, destY = c - 1;

        dist[sourceX][sourceY] = 0;
        queue<State> q; // queue storing dist, and coordinates of node

        // movement is possible only if current coordinate is movable
        if (grid[sourceX][sourceY] == 1)
            return -1;
        // edge case when source and destination are the same
        if (sourceX == destX && sourceY == destY)
            return 1;
        q.push({0, sourceX, sourceY});

        int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1};
        int dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};

        while (!q.empty())
        {
            int d = q.front().d;
            int x = q.front().x, y = q.front().y;
            q.pop();

            // go all possible directions
            for (int i = 0; i < 8; i++)
            {
                int newx = x + dx[i], newy = y + dy[i];
                if (newx >= 0 && newx < r && newy >= 0 && newy < c && grid[newx][newy] == 0)
                {
                    int newd = d + 1;
                    // if new distance is lesser than current to reach here
                    if (newd < dist[newx][newy])
                    {
                        dist[newx][newy] = newd;
                        q.push({newd, newx, newy});

                        if (newx == destX && newy == destY)
                            return newd + 1; // here they are calculating no of nodes rather than jumps
                    }
                }
            }
        }
        return -1; // no path found
    }
};