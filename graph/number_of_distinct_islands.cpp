#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> &grid){
    for(auto row : grid){
        for(auto ele : row) cout << ele << " ";
        cout << "\n";
    }
}

void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int, int>> &vec, int baserow, int basecol){
    vis[row][col] = 1;
    vec.push_back(  {row - baserow, col - basecol}  );
    
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, -1, 0, 1};

    for(int i = 0; i < 4; i++){
        int nxtrow = row + delrow[i];
        int nxtcol = col + delcol[i];
        if(
                0 <= nxtrow && nxtrow < grid.size() // valid row
            &&  0 <= nxtcol && nxtcol < grid[0].size() // valid column
            &&  !vis[nxtrow][nxtcol] //not visited that cell 
            &&  grid[nxtrow][nxtcol] == 1 // must be a land cell 
          ){
            dfs(nxtrow, nxtcol, grid, vis, vec, baserow, basecol);
        }
    }
}

int countDistinctIsland(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int> (m, 0));
    set<vector<pair<int, int>>> dst_islnd;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j] && grid[i][j] == 1){
                vector<pair<int, int>> vec;//stores island(value is passed via reference in function call)
                dfs(i, j, grid, vis, vec, i , j);
                dst_islnd.insert(vec);
            }
        }
    }
    return dst_islnd.size();
}

int main(){
    /* 1 represents land cell */
    /* 0 represents water cell */
    vector<vector<int>> grid = {
        {1,1,0,1,1},
        {1,0,0,0,0},
        {0,0,0,1,1},
        {1,1,0,1,0},
    };
    cout << "Given grid :- \n";
    print(grid);
    cout << "\n\nNumber of distinct islands found : " << countDistinctIsland(grid) << endl;
    return 0;
}
