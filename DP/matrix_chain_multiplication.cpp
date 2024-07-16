//memoization

int f(vector<int> &arr, int i, int j, vector<vector<int>> &dp){
    if(i == j) return  0;
    if(dp[i][j] != -1) return dp[i][j];
    int mincost = 1e9;
    for(int k = i; k <= j-1; k++){
        int curcost =  f(arr, i, k, dp) + (arr[i-1]*arr[k]*arr[j]) + f(arr, k+1, j, dp);
        mincost = min(mincost, curcost);
    }
    return dp[i][j] = mincost;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return f(arr, 1, N-1, dp);
}

//tabulation
int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, 0));//handles base case of i=j
    for(int i = N-1; i >= 1; i--){
        for(int j = i+1; j < N; j++){
            int mincost = 1e9;
            for(int k = i; k <= j-1; k++){
                int curcost = dp[i][k] + (arr[i-1]*arr[k]*arr[j]) + dp[k+1][j];
                mincost = min(mincost, curcost);
            }
            dp[i][j] = mincost;
        }
    }
    return dp[1][N-1];
}
