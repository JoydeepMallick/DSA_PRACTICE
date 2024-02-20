#include<bits/stdc++.h>
#include <vector>
using namespace std;

bool recurDP(int ind, vector<int> &a, int k, vector<vector<int>> &dp){
    if(k == 0) return true;
    if(ind == 0) return a[0] == k;
    if(dp[ind][k] != -1) return dp[ind][k];
    int nottake = recurDP(ind-1, a, k, dp);
    int take = false;
    if(a[ind] <= k) take = recurDP(ind-1, a, k-a[ind], dp);
    return dp[ind][k] = take || nottake;
}

bool subsetsumeqK(vector<int> &a, int k){
    int n = a.size();
    /*
    vector<vector<int>> dp(n, vector<int>(k, -1));
    return recurDP(n-1, a,k,dp);
    */ 
    vector<vector<int>> dp(n, vector<int>(k+1, 0));
    //base cases
    for(int ind = 0; ind < n; ind++) dp[ind][0] = true;
    dp[0][a[0]] = true;
    for(int ind = 1; ind < n; ind++){
        for(int target = 1; target <= k; target++){
            int nottake = dp[ind-1][target];
            int take = false;
            if(a[ind] <= target){
                nottake = dp[ind-1][target - a[ind]];
            }
            dp[ind][target] = (take | nottake);
        }
    }

    return dp[n-1][k];
}

bool subsetsumeqK_spaceopt(vector<int> &a, int k){
    int n = a.size();
    vector<bool> prevrow(k+1, false), currow(k+1, false);
    //base cases 
    prevrow[0] = currow[0] =  true;
    prevrow[a[0]] = true;
    for(int ind =1; ind < n; ind++){
        for(int target= 1; target <= k; target++){
            int nottake = prevrow[target];
            int take = false;
            if(a[ind] <= target){
                take = prevrow[target - a[ind]];
            }
            currow[target] = take | nottake;
        }
        prevrow = currow;
    }
    return prevrow[k];

}

int main(){
    int k = 4;
    vector<int> a = {2,1,3,1};
    //check if any subset sum = k
    cout << subsetsumeqK(a,k) << endl;
    cout << subsetsumeqK_spaceopt(a,k) << endl;
    
}
