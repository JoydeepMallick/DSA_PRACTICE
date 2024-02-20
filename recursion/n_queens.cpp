#include <bits/stdc++.h>
using namespace std;
//================ test print ======================

void printBoard(vector<string> board){
    for(auto it : board){
        cout << it << endl;
    }
}

//==================================================



bool isSafe(int row, int col, vector<string> board, int N){
    int currow = row, curcol = col;

    //upper left diagonal check 
    while(row >= 0 && col >= 0){
        if(board[row][col] == 'Q') return false;
        row--;col--;
    }

    //left horizontal 
    row = currow, col = curcol;
    while(col >=0){
        if(board[row][col] == 'Q') return false;
        col--;
    }

    //left lower diagonal 
    row = currow, col = curcol;
    while(row < N && col >= 0){
        if(board[row][col] == 'Q') return false; 
        row++; col--;
    }

    return true;
}


void solve(int col, vector<string> &board, vector<vector<string>> &ans, int N){
    if(col == N){
        //one possible board created 
        ans.push_back(board);
        return; 
    }

    for(int row = 0; row < N; row++){
        if(isSafe(row, col, board, N)){
            //place the queen
            board[row][col] = 'Q';
            //go to the next col and find next possible  position 
            solve(col+1, board,  ans, N);
            //backtrack after above has completed i.e. erase placed queen  
            board[row][col] = '.';
        }
    }
}


vector<vector<string>> solveNQueens(int N){
    vector<string> board(N, string(N,'.'));
    vector<vector<string>> ans;

    solve(0, board, ans, N);

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
