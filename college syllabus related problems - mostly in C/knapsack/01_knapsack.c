#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000
#define MAX_W 1000

int weight[MAX_N+1];
int value[MAX_N+1];
int dp[MAX_N+1][MAX_W+1];

int max(int a, int b) {
    return a > b ? a : b;
}

int knapsack(int n, int W) {
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (weight[i] > j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
            }
        }
    }
    return dp[n][W];
}

int main() {
    int n = 4, W = 7;
    weight[1] = 1; value[1] = 1;
    weight[2] = 3; value[2] = 4;
    weight[3] = 4; value[3] = 5;
    weight[4] = 5; value[4] = 7;
    int max_value = knapsack(n, W);
    printf("Maximum value that can be achieved: %d\n", max_value);

    W = 5;
    weight[1] = 2; value[1] = 12;
    weight[2] = 1; value[2] = 10;
    weight[3] = 3; value[3] = 20;
    weight[4] = 2; value[4] = 15;
    max_value = knapsack(n, W);
    printf("Maximum value that can be achieved: %d\n", max_value);

    return 0;
}
