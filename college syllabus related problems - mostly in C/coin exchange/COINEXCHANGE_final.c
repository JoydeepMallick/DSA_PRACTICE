
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

int minCoinsCount(int coins[], int n, int sum) {
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

void printArray(int arr[], int n) {
    printf("{");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}

void findCombinations(int coins[], int numCoins, int sum, int maxCoins, int temp[], int currSum, int numUsedCoins, int *numSolutions, int *minNumCoins, int *minCoins) {
    if (currSum == sum) {
        if (numUsedCoins <= maxCoins) {
            (*numSolutions)++;
            if (numUsedCoins < *minNumCoins || *minNumCoins == -1) {
                *minNumCoins = numUsedCoins;
                for (int i = 0; i < numUsedCoins; i++) {
                    minCoins[i] = temp[i];
                }
            }
        }
        return;
    }
    if (currSum > sum || numUsedCoins >= maxCoins) {
        return;
    }
    for (int i = 0; i < numCoins; i++) {
        temp[numUsedCoins] = coins[i];
        findCombinations(coins, numCoins, sum, maxCoins, temp, currSum + coins[i], numUsedCoins + 1, numSolutions, minNumCoins, minCoins);
    }
}

int main() {
// test cases
/*
    int coins[] = {1,2,5};//{2, 5, 3, 6};
    int numCoins = sizeof(coins)/sizeof(coins[0]);
    int sum = 12;//10;
    int maxCoinsAllowed;
*/
    
    int coins[100];// fixing length to at most 100 distinct coins 
    int numCoins, sum, maxCoinsAllowed;
// temporary calculation variables below
    int temp[100];
    int numSolutions = 0;
    int minNumCoins = -1;
    int minCoins[100];
    
    printf("\n\nCoin exchange problem:-\n\n");
    
//user input 

    printf("Enter the total sum : ");
    scanf("%d", &sum);
    
    if(sum < 0){
        printf("Not possible !!!\nProgram terminated");
        return -1;
    }

    printf("Enter number of distinct coins : ");
    scanf("%d", &numCoins);
    printf("Enter all the distinct coins separated by a space : ");
    for(int i = 0; i < numCoins; i++) scanf("%d", &coins[i]);


//outputs
    printf("Number of solutions: %d\n", coinExchange(coins, numCoins, sum));

    maxCoinsAllowed = minCoinsCount(coins, numCoins, sum);
    printf("Minimum number of coins required: %d\n", maxCoinsAllowed);
    
    findCombinations(coins, numCoins, sum, maxCoinsAllowed, temp, 0, 0, &numSolutions, &minNumCoins, minCoins);

    //printf("Total number of ways = %d\n", numSolutions);
    printf("Possible combination(s) for minimum coins used = ");
    printArray(minCoins, minNumCoins);
    
    return 0;
}
