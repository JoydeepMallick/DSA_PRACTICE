#include <bits/stdc++.h>
using namespace std;

int minSubsetSumDiff(vector<int> &arr){
    int n = arr.size();
    int totSum = 0;
    totSum = accumulate(arr.begin(), arr.end(), totSum);
    
    vector<vector<bool>> dp(n, vector<bool>(totSum+1, 0));
    for(int i = 0; i < n; i++) dp[i][0] = true;
    dp[0][arr[0]] = true;
    for(int i = 1; i < n; i++){
        for(int t = 1; t <= totSum; t++ ){
            int nottake = dp[i-1][t];
            int take = false;
            if(arr[i] <= t) take = dp[i-1][t-arr[i]];
            dp[i][t] = take || nottake;
        }
    }

    int mindiff = 1e9;
    for(int s1 = 0; s1 <= totSum/2; s1++){
        int possible = dp[n-1][s1];
        if(possible){
            int s2 = totSum - s1;
            mindiff = min(mindiff, abs(s1-s2));
        }
    }
    return mindiff;
}

int main(){
    vector<int> arr = {3,2,7};
    cout << minSubsetSumDiff(arr) << endl;
}
