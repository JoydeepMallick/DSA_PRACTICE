#include <bits/stdc++.h>
#include <vector>
using namespace std;

int recurDP(vector<vector<int>> &grid, int r, int c, vector<vector<int>> &dp){
    if(c < 0 || c >= grid[0].size()) return -1e9;
    if(r == 0) return grid[r][c];
    
    else if(dp[r][c] != -1) return dp[r][c];
    return dp[r][c] = grid[r][c] + max(recurDP(grid, r-1, c, dp), max(recurDP(grid, r-1, c-1, dp), recurDP(grid, r-1, c+1, dp)));
}

int maximumFallingPathSum(vector<vector<int>> &grid){
    int m = grid.size();
    int n = grid[0].size();
    //m x n grid
    vector<vector<int>> dp(m, vector<int>(n,-1));
    int ans = 0;
    for(int col = 0; col < n; col++){
        ans = max(ans, recurDP(grid, m-1,  col, dp)); //assuming ending point is (m-1, col)
    }
    return ans;
}

int maximumFallingPathSum_iter(vector<vector<int>> &grid){
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;
    //m x n grid
    vector<vector<int>> dp(m, vector<int>(n,-1));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i==0) dp[i][j] = grid[i][j];
            else{
                int up = -1e9, ld = -1e9, rd = -1e9;
                up = dp[i-1][j];
                if(j > 0) ld = dp[i-1][j-1];
                if(j < n-1) rd = dp[i-1][j+1];
                dp[i][j] = grid[i][j] + max({up,ld,rd});
            }

            if(i==n-1) ans = max(ans, dp[n-1][j]);
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> grid = {
        {1,2,10,4},
        {100,3,2,1},
        {1,1,20,2},
        {1,2,2,1},
    };
    cout << maximumFallingPathSum(grid) <<endl;
    cout << maximumFallingPathSum_iter(grid) << endl;
}
