#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<char>>& board){
    cout << "\nBoard now :-\n";
    for(auto row : board){
        for(auto ele : row){
            cout << ele << " ";
        }
        cout << "\n";
    }
}

void dfs(int x, int y, vector<vector<char>>& board, vector<vector<int>>& vis){
    //mark as visited
    vis[x][y] = 1;
    int addrow[4] = {-1, 0, +1, 0};
    int addcol[4] = {0, -1, 0, +1};
    for(int i = 0; i < 4; i++){
        int nxtrow = x + addrow[i];
        int nxtcol = y + addcol[i];
        if(
                0 <= nxtrow && nxtrow < (int)board.size() &&
                0 <= nxtcol && nxtcol < (int)board[0].size() &&
                board[nxtrow][nxtcol] == 'O' &&
                !vis[nxtrow][nxtcol]
          ){
            dfs(nxtrow, nxtcol, board, vis);
        }
    }
}
void solve(vector<vector<char>>& board) {
    int n = board.size(), m = board[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    //four boundaries 0,x  ; x, 0  ; m,x  ; x,m where x is variable
    for(int i = 0; i < m; i++ ){
        // first row
        if(!vis[0][i] && board[0][i] == 'O'){
            dfs(0, i, board, vis);
        }
        // last row
        if(!vis[n-1][i] && board[n-1][i] == 'O'){
            dfs(n-1, i, board, vis);
        }
    }
    for(int i = 0; i < n; i++ ){
        // first column
        if(!vis[i][0] && board[i][0] == 'O'){
            dfs(i, 0, board, vis);
        }
        // last column
        if(!vis[i][m-1] && board[i][m-1] == 'O'){
            dfs(i, m-1, board, vis);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            board[i][j] = (vis[i][j] == 0) ? 'X' : 'O';
        }
    }
}


int main(){
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X', 'O'},
        {'X', 'X', 'O', 'X', 'O'},
        {'X', 'O', 'X', 'O', 'X'},
        {'O', 'O', 'X', 'X', 'X'},
    };
    print(board);
    cout << "\nAfter Board flip ";
    solve(board);
    print(board);
    return 0;
}
