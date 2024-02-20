#include <bits/stdc++.h>
using namespace std;

//================ test print ======================

void printBoard(vector<string> board){
    for(auto it : board){
        cout << it << endl;
    }
}

//==================================================



void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &lowerDiagonal, vector<int> &upperDiagonal, int N){
    if(col == N){
        //one possible board created 
        ans.push_back(board);
        return; 
    }

    for(int row = 0; row < N; row++){
        if(leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[N-1 + col-row] == 0){ // if the cell is safe
            //place the queen
            board[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiagonal[row+col] = 1;
            upperDiagonal[N-1+col-row]  = 1;
            //go to the next col and find next possible  position 
            solve(col+1, board,  ans, leftRow, lowerDiagonal, upperDiagonal, N);
            //backtrack after above has completed i.e. erase placed queen  
            board[row][col] = '.';
            leftRow[row] = 0;
            lowerDiagonal[row+col] = 0;
            upperDiagonal[N-1+col-row]  = 0;

        }
    }
}


vector<vector<string>> solveNQueens(int N){
    vector<string> board(N, string(N,'.'));
    vector<vector<string>> ans;

    vector<int> leftRow(N, 0), upperDiagonal(2*N-1, 0), lowerDiagonal(2*N-1, 0);

    solve(0, board, ans, leftRow, lowerDiagonal, upperDiagonal, N);

    return ans;
}

int main(){
    int N = 4;

    cout << "Possible board configurations for N = " << N << "\n======================\n";
    for(auto board : solveNQueens(N)){
        printBoard(board);
        cout << "======================\n";
    }

    return 0;
}
