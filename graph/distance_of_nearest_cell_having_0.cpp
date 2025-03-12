/*
Note : the leetcode problem states to solve for minimum distance to reach 0

Striver's video is on GFG problem which states to visit 1. Please keep this in mind.

*/



class Solution {
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
            //multisource BFS, so first store all the starting nodes that is with value 1
            int m = mat.size(), n = mat[0].size();
            vector<vector<int>> vis(m, vector<int> (n, 0)), dist(m, vector<int> (n, 0));
            queue< pair<pair<int, int>, int> > q;
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(mat[i][j] == 0){ // we need to reach nearest 0 meaning as a startinh point we take all 0s since they need 0 steps to reach themselves
                        q.push({{i,j}, 0}); // coordinates {i,j} and current steps
                        vis[i][j] = 1;
                    }
                }
            }
            //traverse in queue and fill dist matrix
            while(!q.empty()){
                int x = q.front().first.first, y = q.front().first.second;
                int steps = q.front().second;
                q.pop();
                //we are sure that this step value is minimum for x,y
                //reason : each step we just move 1 steps either up/down/left/right so we gurantee that the nearest neighbour gets marked first with minimum step value and then gets locked as its visited hence no larger step can override it
                dist[x][y] = steps;
                //4 directions movement
                int dx[] = {0, 1, 0, -1};
                int dy[] = {1, 0, -1, 0};
                for(int i = 0; i < 4; i++){
                    int newx = x + dx[i], newy = y+dy[i];
                    if(0<=newx && newx<m && 0<=newy && newy<n && !vis[newx][newy]){
                        vis[newx][newy] = 1;
                        q.push({{newx,newy}, steps+1});//no checking for 0 needed as we start from 1s and each time the 
                    }
                }
            }
            return dist;
        }
    };