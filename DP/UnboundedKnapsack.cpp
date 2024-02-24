#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int recurdp(int ind, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp){
    if(ind == 0){
        return W/wt[0] * val[0];
    }

    if(dp[ind][W] != -1) return dp[ind][W];

    int nottake = recurdp(ind-1, W, val, wt, dp);
    int take = 0;
    if(wt[ind] <= W){
        take = val[ind] + recurdp(ind, W - wt[ind], val, wt, dp);
    }
    return dp[ind][W] = max(take, nottake);
}

int unboundedknapsack_recurdp(int n, int W, vector<int> &val, vector<int> &wt){
    vector<vector<int>> dp(n, vector<int>(W+1, -1));
    return recurdp(n-1, W, val, wt, dp);
}


int unboundedknapsack_iterdp(int n, int W, vector<int> &val, vector<int> &wt){
    vector<vector<int>> dp(n, vector<int>(W+1, 0));
    //when just one item to pick in different ranges of weight try to fillup knapsack by it 
    for(int kW = 0; kW <= W; kW++){
        dp[0][kW] = kW/wt[0] * val[0];
    }

    for(int i = 1; i < n; i++){
        for(int kW = 0; kW <= W; kW++){
            int nottake = dp[i-1][kW];
            int take = 0;
            if(wt[i] <= kW){
                take = val[i] + dp[i][kW - wt[i]];
            }
            dp[i][kW] = max(take, nottake);
        }
    }
    return dp[n-1][W];
}

int main(){
    int n = 3, W = 10;
    vector<int> val = { 5,11,13 }, wt = { 2,4,6 };
    //output = 27
    cout << unboundedknapsack_recurdp(n,W, val, wt) << endl;
    cout << unboundedknapsack_iterdp(n,W, val, wt) << endl;
    return 0;
}
