#include<bits/stdc++.h>
using namespace std;

int f_memo(int n, vector<int> &dp){
    if(n <= 1) return n;

    if(dp[n] != -1) return dp[n];
   
    return dp[n] = f_memo(n-1, dp) + f_memo(n-2, dp);
}

int f_tabu(int n, vector<int> &dp){
    //setting base case
    dp[0] = 0, dp[1] = 1;

    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main(){
    int n = 0;
    cout << "Enter which number in fibonacci to print : ";
    cin >> n;

    vector<int> dp(n+1, -1);

    cout << "Fibonacci by memoization : " << f_memo(n, dp) << endl;
    cout << "Fibonacci by tabulation : " << f_tabu(n, dp) << endl;
}
