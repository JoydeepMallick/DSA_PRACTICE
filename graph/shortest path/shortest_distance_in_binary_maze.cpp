#include <bits/stdc++.h>

// this is 4 way movement, leetcode version allows 8 ways movement
//  also distance calculation based on coordinate count not jumps hence plus 1.

struct State
{
    int d, x, y;
};

int findShortestPath(vector<vector<bool>> &mat,
                     int sourceX, int sourceY,
                     int destX, int destY,
                     int n, int m)
{
    int r = mat.size(), c = mat[0].size();
    int dist[r][c];
    // initilize all dist array
    fill(&dist[0][0], &dist[0][0] + r * c, INT_MAX);

    dist[sourceX][sourceY] = 0;
    queue<State> q; // queue storing dist, and coordinates of node
    q.push({0, sourceX, sourceY});

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    // edge case when source and destination are the same
    if (sourceX == destX && sourceY == destY)
        return 0;

    while (!q.empty())
    {
        int d = q.front().d;
        int x = q.front().x, y = q.front().y;
        q.pop();

        // go all possible directions
        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i], newy = y + dy[i];
            if (newx >= 0 && newx < r && newy >= 0 && newy < c && mat[newx][newy] == 1)
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