#include <stdio.h>
#include <limits.h> //coins INT_MAX 

int min(int a, int b) {
    return (a < b) ? a : b;
}

int minCoins(int coins[], int n, int sum) {
    int dp[sum+1];
    dp[0] = 0;
    
    for (int i = 1; i <= sum; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i) {
                int sub_res = dp[i-coins[j]];
                if (sub_res != INT_MAX && sub_res + 1 < dp[i]) {
                    dp[i] = sub_res + 1;
                }
            }
        }
    }
    return dp[sum];
}

int main() {
    int coins[] = {1,2,5};//{2, 5, 3, 6};
    int n = sizeof(coins)/sizeof(coins[0]);
    int sum = 12;//10;
    printf("Minimum number of coins required: %d\n", minCoins(coins, n, sum));
    return 0;
}
