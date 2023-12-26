
#include<bits/stdc++.h>
using namespace std;

int f_recur(int ind){
    if(ind <= 1) return 1;
    
    int left = f_recur(ind-1);
    int right = f_recur(ind-2);

    return left + right;

}


int f_memo(int n, vector<int> &dp){
    if(n <= 1) return dp[n] = 1;
    if(dp[n] != -1) return dp[n];

    return dp[n] = f_memo(n-1, dp) + f_memo(n-2, dp);
}


int f_tabu(int n, vector<int> &dp){
    //setting base case
    dp[0] = 1, dp[1] = 1;

    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main(){
    int n = 0;
    cout << "Enter final step N : ";
    cin >> n;

    vector<int> dp1(n+1, -1), dp2(n+1, -1);

    cout << "Count by recursion : " << f_recur(n) << endl;
    cout << "Count by memoization : " << f_memo(n, dp1) << endl;
    cout << "Count by tabulation : " << f_tabu(n, dp2) << endl;
}
