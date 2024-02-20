
#include <stdio.h>
#include <limits.h>

#define MAX 1000

int coinExchange(int coins[], int n, int sum)
{
    int dp[MAX] = {0};
    dp[0] = 1; // Base case

    // Fill the dp[] array using bottom-up approach
    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= sum; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    // Return the number of solutions for the given sum
    return dp[sum];
}

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
    //sample for testing 
    int coins[] = {2, 5, 3, 6};
    int n = sizeof(coins)/sizeof(coins[0]);
    int sum = 10;

    printf("Coin exchange problem:-\n\n");
/*
    printf("Enter the total sum : ");
    scanf("%d", &sum);
    
    if(sum < 0){
        printf("Not possible !!!\nProgram terminated");
        return -1;
    }

    printf("Enter number of distinct coins : ");
    scanf("%d", &n);
    printf("Enter all the distinct coins separated by a space : ");
    for(int i = 0; i < n; i++) scanf("%d", &coins[i]);
*/
    int solutions = coinExchange(coins, n, sum);

    printf("Number of solutions: %d\n", solutions);

    printf("Minimum number of coins required: %d\n", minCoins(coins, n, sum));

    return 0;
}
