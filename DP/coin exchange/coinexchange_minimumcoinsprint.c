
#include <stdio.h>
#include <stdlib.h>

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
    int coins[] = {1,2,5};//{2, 5, 3, 6};
    int numCoins = 3;//4;
    int sum = 12;//10;
    int maxCoins = 3;//2;
    int temp[100];
    int numSolutions = 0;
    int minNumCoins = -1;
    int minCoins[100];
    
    findCombinations(coins, numCoins, sum, maxCoins, temp, 0, 0, &numSolutions, &minNumCoins, minCoins);
    
    printf("Total number of ways = %d\n", numSolutions);
    printf("Possible combinations for minimum coins used = ");
    printArray(minCoins, minNumCoins);
    
    return 0;
}
