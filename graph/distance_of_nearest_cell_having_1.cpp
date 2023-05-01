#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> &grid){
    for(auto row : grid){
        for(auto ele : row) cout << ele << " ";
        cout << "\n";
    }
    cout << endl;
}

vector<vector<int>> nearestCell_having_1(vector<vector<int>> &grid){
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> ans(n, vector<int>(m, 0));//needs predefinations since we place data directly into location
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;
    //traverse through all cells and insert cells containing 1 into queue(problem similar to rotten oranges)
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 1){
                vis[i][j] = 1;//mark as visited 
                q.push({{i,j}, 0});// insert coordinates and its value in ans 
            }
        }
    }
    int addrow[4] = {-1, 0, +1, 0};
    int addcol[4] = {0, -1, 0, +1};
    while(!q.empty()){
        int currow = q.front().first.first;
        int curcol = q.front().first.second;
        int nearestdist = q.front().second;
        ans[currow][curcol] = nearestdist;//fill the ans matrix 
/* cout << "Till now ans matrix is :-\n"; */
/* print(ans); */
        q.pop();
        for(int i = 0; i < 4; i++){
            int nxtrow = currow + addrow[i];
            int nxtcol = curcol + addcol[i];
            if(
                    0 <= nxtrow && nxtrow < n && 
                    0 <= nxtcol && nxtcol < m &&
                    !vis[nxtrow][nxtcol]
            ) {// if valid nextrow and nextcol
                q.push({ {nxtrow, nxtcol}, nearestdist + 1}); 
                //mark as visited
                vis[nxtrow][nxtcol] = 1;
            }
        }
    }

    cout << "Visited array :- \n";
    print(vis);
    return ans;
}

int main(){
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 0, 0},
    };
    cout << "01 Matrix :-\n\n";
    print(grid);
    /*
        expected output 
        1  1  1
        1  0  1
        0  1  2

        since possible movement directions are top bottom left and right.
     */
    vector<vector<int>> ans =  nearestCell_having_1(grid);
    cout << "Answer :-\n\n";
    print(ans);
    return 0;
}

