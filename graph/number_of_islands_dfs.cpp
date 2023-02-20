#include<bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<bool>> &vis){
    //mark the '1' coordinate currently provided as visited
    vis[row][col] = true;
    int n = grid.size();//no of rows
    int m = grid[0].size();//no of columns
                           //the given slution assumes 8 directions
    /*for(int delrow = -1; delrow < n; delrow++){
      for(int delcol = -1; delcol < m; delcol++){
      int nb_row = row + delrow;
      int nb_col = col + delcol;
      if(
      0 <= nb_row && nb_row < n &&
      0 <= nb_col && nb_col < m && 
      grid[nb_row][nb_col] == '1' &&//must be land
      !vis[nb_row][nb_col]//not visited
      ){
      dfs(nb_row, nb_col, grid, vis);
      }
      }
      }*/
    //below solution assumes on 4 directions 
    for(int i : {-1,1}){
        int nb_row = row + i;
        int nb_col = col + i;
        if(0<=nb_row && nb_row < n && grid[nb_row][col] == '1' &&
                !vis[nb_row][col]){
            dfs(nb_row, col, grid, vis);
        }
        if(0<=nb_col && nb_col < m && grid[row][nb_col] == '1' &&
                !vis[row][nb_col]){
            dfs(row, nb_col, grid, vis);
        }
    }

}

int numIslands(vector<vector<char>>& grid) {
    if(grid.size() == 0) return 0;
    int n = grid.size();
    int m = grid[0].size();
    int cnt = 0;
    vector<vector<bool>> vis(n, vector<bool> (m, false));//visited array
    for(int i  = 0; i < n; i++){
        for(int j = 0; j < m ; j++){
            if(!vis[i][j] && grid[i][j] == '1'){
                cnt++;
                dfs(i,j,grid, vis);
            }
        }
    }
    return cnt;
}


int main(){
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'0','1','0','0','1'},
        {'1','0','0','1','1'},
        {'0','0','0','0','0'},
        {'1','0','1','1','0'},
        {'0','0','0','1','0'},
    };

    /*
     *          ie. total 4 islands  for 8 directions 
     *             total 5 islands for 4 direction movement.
     */
    cout << "\n\nNumber of islands : " << numIslands(grid) << endl;
    return 0;
}
