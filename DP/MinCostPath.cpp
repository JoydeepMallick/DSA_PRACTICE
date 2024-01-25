#include <iostream>
#include <vector>
#include <bit>
#include <ostream>
using namespace std;

int mincostpath(int r, int c, vector<vector<int>> &cost){
    if(r==0 && c==0) return cost[r][c];
    if(r < 0 || c < 0) return 1e9; // dont return INT_MAX since then the calculation will have integer overflow result  in startinf from -ve values counting leading to unwanted result
    int up = 0, left = 0;
    up = cost[r][c] + mincostpath(r, c-1, cost);
    left = cost[r][c] + mincostpath(r-1, c, cost);
    return min(left, up);
}

int mincostpath_recurDP(int r, int c, vector<vector<int>> &cost, vector<vector<int>> &dp){
    if(r==0 && c==0) return cost[r][c];
    if(r < 0 || c < 0) return 1e9; // dont return INT_MAX since then the calculation will have integer overflow result  in startinf from -ve values counting leading to unwanted result
    if(dp[r][c] != -1) return dp[r][c];
    int up = 0, left = 0;
    up = cost[r][c] + mincostpath(r, c-1, cost);
    left = cost[r][c] + mincostpath(r-1, c, cost);
    return dp[r][c] = min(left, up);
}

int mincostpath_iterDP(int r, int c, vector<vector<int>> &cost){
    vector<vector<int>> dp(r+1, vector<int>(c+1 , -1));
    for(int i = 0; i <= r; i++){
        for(int j = 0; j <= c; j++){
            if(i == 0 &&  j == 0){
                dp[i][j] = cost[i][j];
            }
            else{
                //from current cell cost is accounted below and then do movements as needed
                int left = cost[i][j], up = cost[i][j];
                if(i > 0) up += dp[i-1][j];
                else up += 1e9;//out of boundary hence cant be taken into account
                if(j > 0) left += dp[i][j-1];
                else left += 1e9;//out of boundary hence cant be taken into account
                dp[i][j] = min(left, up);
            }
        }
    }
    return dp[r][c];
}

int mincostpath_optDP(int r, int c, vector<vector<int>> &cost){
    vector<int> prev(c+1, -1);

    for(int i = 0; i <= r; i++){
        vector<int> cur(c+1, -1);
        for(int j = 0; j <= c; j++){
            if(i == 0 &&  j == 0){
                cur[j] = cost[i][j];
            }
            else{
                //from current cell cost is accounted below and then do movements as needed
                int left = cost[i][j], up = cost[i][j];
                if(i > 0) up += prev[j];
                else up += 1e9;//out of boundary hence cant be taken into account
                if(j > 0) left += cur[j-1];
                else left += 1e9;//out of boundary hence cant be taken into account
                cur[j] = min(left, up);
            }
        }
        prev = cur;
    }
    return prev[c];
}

int main(){
    int n = 2, m = 3;
    vector<vector<int>> cost = { 
        {5,9,6},
        {11,5,2}
    };
    cout << mincostpath(n-1, m-1, cost) << endl;
    vector<vector<int>> dp(n, vector<int>(m , -1));
    cout << mincostpath_recurDP(n-1, m-1, cost, dp) << endl;
    cout << mincostpath_iterDP(n-1, m-1, cost) << endl;
    cout << mincostpath_optDP(n-1, m-1, cost) << endl;
}
