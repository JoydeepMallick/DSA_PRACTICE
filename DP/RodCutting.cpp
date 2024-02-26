#include <iostream>
#include <vector>
using namespace std;

//___________________________________ coding ninjas version_____________________________________

int recurdp_CN(vector<int> &price, int ind, int rodlen, vector<vector<int>> &dp){
    if(ind == 0){ // 1 based indexing
        return rodlen * price[0]; // remaining length will be all of size 1 the base case
    }
    if(dp[ind][rodlen] != -1) return dp[ind][rodlen];

    int nottake = 0 + recurdp_CN(price, ind -1, rodlen , dp);
    int take = INT_MIN;
	int piecelen = ind+1;
    if(rodlen >= piecelen){
        take = price[ind] + recurdp_CN(price, ind, rodlen - piecelen, dp);
    }
    return dp[ind][rodlen] = max(take, nottake);
}

int cutRod_recurdp_CN(vector<int> &price, int n ){
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    return recurdp_CN(price, n-1, n, dp);
}

int cutRod_iterdp_CN(vector<int> &price, int n){
    vector<vector<int>> dp(n, vector<int>(n+1, 0));
    //piece of size 1 only exists meaning ind = 0
    for(int rodlen = 1; rodlen <= n; rodlen++){
        dp[0][rodlen] = rodlen * price[0];
    }

    for(int ind = 1; ind < n; ind++){
        int piecesize = ind+1;
        for(int rodlen = 1; rodlen <= n; rodlen++){
            int nottake = 0 + dp[ind-1][rodlen];
            int take = 0;
            if(rodlen >= piecesize){
                take = price[ind] + dp[ind][rodlen - piecesize];
            }
            dp[ind][rodlen] = max(take, nottake);
        }
    }
    return dp[n-1][n];
}


//-----------------------------------------------------------------------------------------------


int cutRod_iterdp(vector<int> &price, int n){
    //simple unbound knapsack
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    //piece of size 1 only exists
    for(int rodlen = 1; rodlen <= n; rodlen++){
        dp[1][rodlen] = rodlen * price[1];
    }

    for(int piecesize = 2; piecesize <= n; piecesize++){
        for(int rodlen = 1; rodlen <= n; rodlen++){
            int nottake = dp[piecesize-1][rodlen];
            int take = 0;
            if(rodlen >= piecesize){
                take = price[piecesize] + dp[piecesize][rodlen - piecesize];
            }
            dp[piecesize][rodlen] = max(take, nottake);
        }
    }
    return dp[n][n];
}

int recurdp(vector<int> &price, int ind, int rodlen, vector<vector<int>> &dp){
    if(ind == 1){ // 1 based indexing
        return rodlen * price[1]; // remaining length will be all of size 1 the base case
    }
    if(dp[ind][rodlen] != -1) return dp[ind][rodlen];

    int nottake = 0 + recurdp(price, ind -1, rodlen , dp);
    int take = INT_MIN;
    if(rodlen >= ind){
        take = price[ind] + recurdp(price, ind, rodlen - ind, dp);
    }
    return dp[ind][rodlen] = max(take, nottake);
}

int cutRod_recurdp(vector<int> &price, int n ){
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return recurdp(price, n, n, dp);
}


//NOTE:
//coding ninjas tells to assume 1 based indexing but array is 0 based so rod piece length = ind + 1 so see code
int main(){
    int rodlength =  5;
    vector<int> price = {0, 2, 5, 7, 8, 10}; // 1 based indexing
    cout << cutRod_recurdp(price, rodlength) << endl;// 12
    cout << cutRod_iterdp(price, rodlength) << endl;
    //coding ninjas only 
    price = { 2, 5, 7, 8, 10}; // 1 based indexing
    cout << cutRod_recurdp_CN(price, rodlength) << endl;// 12
    cout << cutRod_iterdp_CN(price, rodlength) << endl;

    rodlength = 8;
    price = {0,3, 5, 8, 9, 10, 17, 17, 20};
    cout << cutRod_recurdp(price, rodlength) << endl; // 24
    cout << cutRod_iterdp(price, rodlength) << endl;
    //coding ninjas only 
    price = {3, 5, 8, 9, 10, 17, 17, 20};
    cout << cutRod_recurdp_CN(price, rodlength) << endl; // 24
    cout << cutRod_iterdp_CN(price, rodlength) << endl;

    return 0;
}
