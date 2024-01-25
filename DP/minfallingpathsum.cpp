#include <bits/stdc++.h>
using namespace std;

/*
//recursive apporach 
int allpossible(vector<vector<int>>& m, int r, int c){
    int n  = m.size();
    //invalid row or col
    if(c <= -1 || c >= n) return 1e9;
    //base case
    if(r == n-1 && 0 <= c && c <= n-1) return m[r][c];
    int ld = 1e9,rd = 1e9, b = 1e9;
    ld = m[r][c] + allpossible(m, r+1,c-1);
    rd = m[r][c] + allpossible(m, r+1,c+1);
    b =  m[r][c] + allpossible(m, r+1, c);
    return min(ld,min(rd,b));
}

int minFallingPathSum(vector<vector<int>>& matrix) {
    //greedy apporach is not feasible because it might occur that choosing a smaller value at previous row leads to choice remainng in the current row as the largest value
    //so need to consider all paths(recursive)
    int ans = INT_MAX;
    for(int col = 0; col < matrix.size(); col++){
        ans = min(ans, allpossible(matrix,0, col));
    }
    return ans;
}
*/

/*

int recurDP(vector<vector<int>> &m, int r, int c, vector<vector<int>> &dp){
    int n = m.size();
    //reached outside boundary hence invalid
    if(c <= -1 || c >= n) return 1e9;
    //base case in last row
    if(r == n-1 && 0 <= c && c <= n-1) return  m[r][c];
    if(dp[r][c] != -1) return dp[r][c];

    int ld = 1e9, rd = 1e9, b = 1e9;
    ld = m[r][c] + recurDP(m, r+1, c-1, dp);
    rd = m[r][c] + recurDP(m, r+1, c+1, dp);
    b = m[r][c] + recurDP(m, r+1, c, dp);

    return dp[r][c] = min(ld, min( rd, b ));
}

int minFallingPathSum(vector<vector<int>> &matrix){
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(n,-1));
    int ans = INT_MAX;
    for(int col = 0; col < n; col++){
        ans = min(ans, recurDP(matrix, 0, col, dp));
    }
    return ans;
}
*/

/*
 //iterative dp 
int minFallingPathSum(vector<vector<int>> &matrix){
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(n,-1));
    int ans = INT_MAX;
    //base case 
    for(int c = 0; c < n; c++){
        dp[0][c] = matrix[0][c];
    }
    //computing dp iteratively by checking prev row 
    for (int r = 1; r < n; r++) {
        for (int c = 0; c < n; c++) {
            //in case of invalid take a extremely large value
            int lastleft = 1e9, lastright = 1e9, lastup = 1e9;
            if(c > 0) lastleft = dp[r-1][c-1]; 
            if(c < n-1) lastright = dp[r-1][c+1];
            lastup = dp[r-1][c];
            dp[r][c] = matrix[r][c] + min(lastup, min(lastleft, lastright));
        }
    }
    for(int col = 0; col < n; col++){
        ans = min(ans, dp[n-1][col]);
    }
    return ans;

}
*/ 

int minFallingPathSum(vector<vector<int>> &matrix){
    int n = matrix.size();
    vector<int> prevrow(n,-1);
    int ans = INT_MAX;
    //base case 
    for(int c = 0; c < n; c++){
        prevrow[c] = matrix[0][c];
    }
    //computing dp iteratively by checking prev row 
    for (int r = 1; r < n; r++) {
        vector<int> currow(n, -1);
        for (int c = 0; c < n; c++) {
            //in case of invalid take a extremely large value
            int lastleft = 1e9, lastright = 1e9, lastup = 1e9;
            if(c > 0) lastleft = prevrow[c-1]; 
            if(c < n-1) lastright = prevrow[c+1];
            lastup = prevrow[c];
            currow[c] = matrix[r][c] + min(lastup, min(lastleft, lastright));
        }
        prevrow = currow;
    }
    for(int col = 0; col < n; col++){
        ans = min(ans, prevrow[col]);
    }
    return ans;

}
int main(){
    vector<vector<int>> matrix = {{-19,57},{-40,-5}}; 
    cout << minFallingPathSum(matrix) << endl;

    matrix = {{2,1,3},{6,5,4},{7,8,9}};
    cout << minFallingPathSum(matrix) << endl;
        return 0;
}
