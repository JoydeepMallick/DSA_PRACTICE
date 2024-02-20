#include <bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<char>> board){
    for(auto it : board){
        for(auto it2 : it) cout << it2 << " ";
        cout << endl;
    }
    cout << "\n";
}

bool isValid(vector<vector<char>> &board, int row, int col, char c){
    for(int i = 0; i < 9; i++){
        if(board[i][col] == c) return false; // checking in current col
        if(board[row][i] == c) return false; // checking in current row
        if(board[3 * (row/3) + i/3][3 * (col/3) + i%3] == c) return false;//check entire 3x3 box
    }
    return true;
}

bool solve(vector<vector<char>> &board){
    for(int i = 0; i < (int)board.size(); i++){
        for(int j = 0; j < (int)board[0].size(); j++){
            
            if(board[i][j] == '.'){
                
                for(char c = '1'; c <= '9'; c++){
                    if(isValid(board, i, j, c)){
                        board[i][j] = c;
                       
/* printBoard(board); */

                        if(solve(board) == true) return true;
                        else board[i][j] = '.';//reset
                    }
                } 

                return false;
            }
        }
    }

    return true;
}

void solveSudoku(vector<vector<char>> &board){
    solve(board);//inplace updation of board 
}



int main(){
    vector<vector<char>> sudoku = {
        {'5', '3', '.', '6', '7', '8', '9', '.', '2'},
        {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
        {'.', '9', '8', '3', '4', '2', '5', '6', '7'},
        {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
        {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
        {'7', '1', '3', '9', '.', '4', '8', '5', '6'},
        {'9', '6', '.', '5', '3', '7', '2', '8', '4'},
        {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
        {'3', '4', '5', '2', '8', '6', '1', '7', '9'},
    }; 

    solveSudoku(sudoku);

    printBoard(sudoku);
}
