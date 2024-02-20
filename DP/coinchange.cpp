#include <bits/stdc++.h>
using namespace std;


int coinChange_iterDP(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount+1, 0));
    //base case 
    for(int A = 0; A <= amount; A++){
        if(A%coins[0] == 0){
            dp[0][A] = A/coins[0];
        }
        else{
            //this move is invalid for index 0
            dp[0][A] = 1e9;
        }
    }

    for(int ind = 1; ind < n; ind++){
        for(int A = 0; A <= amount; A++){
            int nottake = 0 + dp[ind-1][A];
            int take = 1e9;
            if(coins[ind] <= A){
                take = 1 + dp[ind][A - coins[ind]];
            }
            dp[ind][A] = min(take, nottake);
        }
    }

    int ans = dp[n-1][amount];
    return (ans >= 1e9)?-1:ans;
}



int mincoins(vector<int> &coins,int ind, int am, vector<vector<int>> &dp){
    if(ind == 0){
        if(am % coins[0]  == 0){
            return am/coins[0];
        }
        else return 1e9;
    }
    if(am == 0){
        return 0;
    }
    if(dp[ind][am] != -1) return dp[ind][am];
    int nottake = 0 + mincoins(coins, ind-1, am, dp);
    int take = 1e9;
    if(coins[ind] <= am){
        take = 1 + mincoins(coins, ind, am - coins[ind], dp);
    }
    return dp[ind][am] = min(take, nottake);
}

int coinChange_recurDP(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount+1, -1));
    int ans = mincoins(coins, n-1, amount, dp);
    return (ans == 1e9)?-1:ans;
}


int main(){
    vector<int> coins = {1,3,2};
    int target = 7; // ans = 3
    cout << coinChange_iterDP(coins, target);
    return 0;
}
