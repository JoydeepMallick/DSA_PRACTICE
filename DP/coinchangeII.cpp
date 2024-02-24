#include <iostream>
#include <vector>
using namespace std;

// simple debugger to see flow of code just prints the array values
void print(vector<int> &arr){
    cout << "{ ";
    for(auto ele : arr){
        cout << ele << " ";
    }
    cout << "}\n";
}

// ends 


int recurDP(vector<int> &coins, int ind, int amount, vector<vector<int>> &dp){
    if(ind == 0){
        //either take all if possible to divide completely
        if(amount % coins[0] == 0) return 1;
        //else return impossible 
        else return 0;
    }

    if(dp[ind][amount] != -1) return dp[ind][amount];

    int nottake = recurDP(coins, ind-1, amount, dp);
    int take = 0;
    if(coins[ind] <= amount){
        take = recurDP(coins, ind, amount - coins[ind], dp);
    }

    return dp[ind][amount] = take + nottake;

}

int change_recurDP(vector<int> &coins, int amount){
    int n =  coins.size();
    vector<vector<int>> dp(n, vector<int>(amount+1, -1));
    return recurDP(coins, n-1, amount, dp);
}

int change_iterDP(vector<int> &coins, int amount){
    int n = coins.size();
    vector<int> prev(amount+1, 0), cur(amount+1, 0);
    for(int A = 0; A <= amount; A++){
        prev[A] = (A%coins[0] == 0);
    }

    print(prev);//dbg

    for(int ind = 1; ind < n; ind++){
        for(int A = 0; A <= amount; A++){
            int nottake = prev[A];
            int take = 0;
            if(A >= coins[ind]) take = cur[A - coins[ind]];
            cur[A] = take + nottake;
        }
        prev = cur;
        print(prev); //dbg
    }
    return prev[amount];
}


//passes leetcode explanation to be thought of
int change_onevar(vector<int> &coins, int amount){
    int n = coins.size();
    vector<int> prev(amount+1, 0);
    for(int A = 0; A <= amount; A++){
        prev[A] = (A%coins[0] == 0);
    }

    print(prev); //dbg

    for(int ind = 1; ind < n; ind++){
        for(int A = 0; A <= amount; A++){
            int nottake = prev[A];
            int take = 0;
            if(A >= coins[ind]) take = prev[A - coins[ind]];
            prev[A] = take + nottake;
        }
        print(prev); //dbg
    }
    return prev[amount];
}


int main(){
    vector<int> coins = {1,2,5};
    int amount = 5;
    cout << change_recurDP(coins, amount) << endl;
    cout << change_iterDP(coins, amount) << endl;
    cout << change_onevar(coins, amount) << endl;
    coins = {5,3,1, 2};
    amount = 4;
    cout << change_iterDP(coins, amount) << endl;
    cout << change_onevar(coins, amount) << endl;
}
