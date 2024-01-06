#include <bits/stdc++.h>
using namespace std;
int totalPaths_recurDP(int i, int j, vector<vector<int>> &dp){
    if(i == 0 && j == 0) return dp[0][0] = 1;
    if(i < 0 || j < 0) return 0;
    if(dp[i][j] > -1) return dp[i][j];

    //possible movements
    int left = totalPaths_recurDP(i-1, j, dp);
    int up = totalPaths_recurDP(i, j-1, dp);

    //return sum
    return dp[i][j] = (left + up);
}

int totalPaths_iterDP(int destrow, int destcol, vector<vector<int>> &dp){
    for(int i = 0; i <= destrow; i++){
        for(int j = 0; j <= destcol; j++){
           if(i == 0 && j == 0)  {
               dp[0][0] = 1;
           }
           else
           {
               int left = 0, up = 0;
               if(i>0) up = dp[i-1][j];
               if(j>0) left = dp[i][j-1];
               dp[i][j] = left + up;
           }
        }
    }
    return dp[destrow][destcol];
}



int totalPaths_optDP(int destrow, int destcol){
    vector<int> prevrow(destcol+1, -1);
    for (int i = 0; i <= destrow; i++) {
        vector<int> currow(destcol+1, -1);
        for (int j = 0; j <= destcol; j++) {
            if(i == 0 && j == 0) currow[j] = 1;
            else{
                int left = 0, up = 0;
                if(i > 0) up = prevrow[j];//similar to iterative just i index is removed
                if(j > 0) left = currow[j-1];
                currow[j] = left + up;
            }
        }
        //reset prevrow    
        prevrow = currow;
    }
    return prevrow[destcol];
}

int main(){
    int m = 3, n = 3;
    vector<vector<int>> dp(m, vector<int>(n,-1));
    cout << "Total number of paths via recursive DP = " << totalPaths_recurDP(m-1,n-1,dp) <<endl;
    cout << "Total number of paths via iterative DP = " << totalPaths_iterDP(m-1,n-1,dp) <<endl;
    cout << "Total number of paths via optimized DP = " << totalPaths_optDP(m-1,n-1) <<endl;
    return 0;
}
