#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> &wt, vector<int> &val, int n, int W){
    vector<int> prev(W+1, 0);
    for(int bagW = wt[0]; bagW <= W; bagW++){
        prev[bagW] = val[0];
    }

    for(int ind = 1; ind < n; ind++){
        for(int bagW = W; bagW >= 0; bagW--){
            int nottake = 0 + prev[bagW];
            int take = INT_MIN;
            if(wt[ind] <= bagW){
                take = val[ind] + prev[bagW-wt[ind]];
            }

            prev[bagW] = max(take, nottake);
        }
    }

    return prev[W];
}

int main(){
    vector<int> wt = {2,3,5};
    vector<int> val = {30, 40, 60};
    int maxWeight = 6;

    cout << knapsack(wt,val,3,maxWeight) << endl;
    return 0;
}
