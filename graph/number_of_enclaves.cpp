#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> &grid){
    for(auto row : grid){
        for(auto ele : row) cout << ele << " ";
        cout << "\n";
    }
}

int numberOfEnclaves(vector<vector<int>> &grid){
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> vis(n, vector<int> (m,0));
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
           if((i==0 || j==0 || i==n-1 || j==m-1) && grid[i][j] == 1){
            //first row, first column, last row, last column 
            q.push({i,j});
/* cout << i << " ," << j << endl; */
            vis[i][j] = 1; //<-- do mark visited immediately after pushing to avoid same coordinate getting pushed multiple times when queue traversal starts

           }
        }
    }
    
    int addrow[4] = {-1, 0, +1, 0};
    int addcol[4] = {0, -1, 0, +1};
    while(!q.empty()){
        int row = q.front().first, col = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nxtrow = row + addrow[i];
            int nxtcol = col + addcol[i];
            if(
                0<=nxtrow && nxtrow<n &&
                0<=nxtcol && nxtcol<m &&
                grid[nxtrow][nxtcol] == 1 &&
                !vis[nxtrow][nxtcol]
            ){
                q.push({nxtrow, nxtcol});
                vis[nxtrow][nxtcol] = 1;// <-- do mark visited immediately after pushing to avoid same coordinate getting pushed multiple times when queue traversal starts
            }
        }
    }

/* cout << "Visited array :-\n"; */
/* print(vis); */

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(!vis[i][j] && grid[i][j]) cnt++;
        }
    }

    return cnt;
}

int main(){
    /* 1 represents land cell */
    /* 0 represents water cell */
    vector<vector<int>> grid = {
        {0,0,0,1,1},
        {0,0,1,1,0},
        {0,1,0,0,0},
        {0,1,1,0,0},
        {0,0,0,1,1},
    };
    cout << "Given grid :- \n";
    print(grid);
    cout << "\n\nNumber of enclaves found : " << numberOfEnclaves(grid) << endl;
    return 0;
}
