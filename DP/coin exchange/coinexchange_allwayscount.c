#include <stdio.h>
#define MAX 1000

int coinExchange(int coins[], int n, int sum)
{
    //int dp[sum+1];
    int dp[MAX] = {0};
    dp[0] = 1; // Base case

    // Initialize all values in dp as 0
/* for (int i = 1; i <= sum; i++) */
/* dp[i] = 0; */

    // Fill the dp[] array using bottom-up approach
    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= sum; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    // Return the number of solutions for the given sum
    return dp[sum];
}

int main()
{
/* int sum = 10; */
/* int coins[] = {2, 5, 3, 6}; */
/* int n = sizeof(coins) / sizeof(coins[0]); */

    int n, sum;
    int coins[MAX];
    printf("Enter the total sum : ");
    scanf("%d", &sum);
    if(sum < 0){
        printf("Not possible !!!\nProgram terminated");
        return -1;
    }
    printf("Enter number of distinct coins : ");
    scanf("%d", &n);
    printf("Enter all the distinct coins seperated by a space : ");
    for(int i = 0; i < n; i++) scanf("%d", &coins[i]);

    int solutions = coinExchange(coins, n, sum);

    printf("Number of solutions: %d\n", solutions);

    return 0;
}

/*
 sum 12 

 coins 1 2 5 

 solutions = 13
 */
