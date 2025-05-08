class Solution {
    private:
        bool dfs(vector<vector<char>> &grid, vector<vector<int>> &vis, int currow, int curcol, int prevrow, int prevcol, char val){
            int  m = grid.size(), n = grid[0].size();
            int dx[] = {0,1,0,-1};
            int dy[] = {1,0,-1,0};
            vis[currow][curcol] = 1;
            for(int i = 0; i < 4; i++){
                int nrow = currow + dx[i];
                int ncol = curcol + dy[i];
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == val){
                    if(!vis[nrow][ncol]){                    
                        if(dfs(grid, vis, nrow, ncol, currow, curcol, val)) return true;
                    }else if(nrow != prevrow || ncol != prevcol){
                        //visited but coordinates do not match prev coordinate hence loop found
                        return true;
                    }
                }
            }
            return false;
        }
    
    public:
        bool containsCycle(vector<vector<char>>& grid) {
            int  m = grid.size(), n = grid[0].size();
            vector<vector<int>> vis(m, vector<int> (n, 0));
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(!vis[i][j]){
                        if(dfs(grid, vis, i, j, -1, -1, grid[i][j])) return true;
                    }
                }
            }
            return false;
        }
    };