#include <bits/stdc++.h>
using namespace std;

int recursiveCalculation(vector<int> &arr, int ind){
    if(ind == 0) return arr[ind];
    if(ind < 0) return 0; 
    int pick =  arr[ind] + recursiveCalculation(arr, ind-2);
    int notpick = 0 + recursiveCalculation(arr, ind-1);

    return max(pick, notpick);
}


//recursive dp or top down approach
int dpCalculation(vector<int> &arr,int ind, vector<int> &dp){
    if(ind == 0) return dp[ind] = arr[ind];
    if(ind < 0) return 0;
    //this line must be below above lines else dp[-1] will cause strange result
    if(dp[ind] != -1) return dp[ind];
    int pick = arr[ind] + dpCalculation(arr, ind-2, dp);
    int notpick = 0 + dpCalculation(arr, ind-1, dp);

    return dp[ind] = max(pick, notpick);
}

//iterative dp
int idp(vector<int> &arr, int ind, vector<int> &dp){
    dp[0] = arr[0];
    
    for(int i = 1; i <= ind; i++){
        int pick = arr[i];
        if(i -2 >= 0){
            pick += dp[i-2]; 
        }
        int notpick = 0 + dp[i-1];

        dp[i] = max(pick, notpick);
    }

    return dp[ind];

}

//space optimization on iterative DP 
int opt_idp(vector<int> &arr, int ind){
    int prevele = arr[0];
    int nonadjele;
    for(int i = 1; i <= ind; i++ ){
        int pick = arr[i];
        if(i-2 >= 0){
            pick += nonadjele; 
        }
        int notpick = 0 + prevele;

        int curi = max(pick, notpick);
        nonadjele = prevele;
        prevele = curi;
    }

    return prevele;
}

int maxSubsequenceSum(vector<int> &arr){
    //return recursiveCalculation(arr, arr.size()-1);
    int n = arr.size();
    vector<int> dp(n, -1) ;
/* return dpCalculation(arr, n-1, dp); */
/* return idp(arr, n-1, dp); */
    return opt_idp(arr, n-1);
}

int main(){
    vector<int> arr = {2,1,4,9}; // ans = 11 
    cout << "max sum of possible subsequence : " << maxSubsequenceSum(arr) << endl;
    return 0;
}
