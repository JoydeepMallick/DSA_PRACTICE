#include "bits/stdc++.h"
using namespace std;

void subsetsumcalc(int N, int ind, int s, vector<int> &arr, vector<int> &sumarr){
    if(ind == N){
        sumarr.push_back(s);
        return; 
    }

    //pick element 
    subsetsumcalc(N, ind+1, s+arr[ind], arr, sumarr);

    //dont pick element 
    subsetsumcalc(N, ind+1, s, arr, sumarr);
}

vector<int> subsetSum(int N, vector<int> arr){
    vector<int> sumarr;
    subsetsumcalc(N, 0, 0, arr, sumarr);
    sort(sumarr.begin(), sumarr.end());
    return sumarr;
}

int main(){
    vector<int> arr = {1,2,2};
    int n = 3;
    for(auto it : subsetSum(n, arr)){
        cout << it << " ";
    }

    cout << endl;
    return 0;
}
