#include <bits/stdc++.h>
using namespace std;

//memoization
int f(int ind, vector<int> &heights, vector<int> &dp){
    if(ind == 0) return 0;
    if(dp[ind] != -1) return dp[ind];

    int left = f(ind-1, heights, dp) + abs(heights[ind] - heights[ind-1]);
    int right = INT_MAX;
    if(ind > 1){
        right = f(ind-2, heights, dp) + abs(heights[ind] - heights[ind-2]);
    }

    return dp[ind] = min(left, right);
}


int frogJump(int n, vector<int> &heights){
    vector<int> dp(n+1, -1);
    return f(n-1, heights, dp);
}


//tabulation
int frogJump1(int n, vector<int> &heights){
    vector<int> dp(n, 0);
    dp[0] = 0;

    for(int i = 1; i < n; i++){
        int fs = dp[i-1] + abs(heights[i-1] - heights[i] );
        int ss = INT_MAX;
        if(i > 1) ss = dp[i-2] + abs(heights[i-2] - heights[i] );

        dp[i] = min(fs, ss);
    }

    return dp[n-1];
}

//space optimization
int frogJump2(int n, vector<int> &heights){
    int prev = 0, prev2 = 0;
    for(int i = 1; i < n; i++){
        int fs = prev + abs(heights[i-1] - heights[i]);
        int ss = INT_MAX;
        if(i > 1) ss = prev2 + abs(heights[i-2] - heights[i]);

        int curi = min(fs, ss);
        prev2 = prev;
        prev = curi;
    }

    return prev;
}



int main(){
    int n1 = 8, n2 = 6;
    vector<int> stairs1 = {7,4,4,2,6,6,3,4}, stairs2 = {4,8,3,10,4,4};

    cout << frogJump(n1, stairs1) <<" " << frogJump1(n1, stairs1) <<" " << frogJump2(n1, stairs1) << endl;
    cout << frogJump(n2, stairs2) <<" " <<  frogJump1(n2, stairs2) <<" " << frogJump2(n2, stairs2) << endl;
}
