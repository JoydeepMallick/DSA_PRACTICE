#include <bits/stdc++.h>
using namespace std;

int noofwaystoachievetarget(vector<int> &arr, int amount){
    int n = arr.size();
    int totalsum = 0;
    totalsum = accumulate(arr.begin(), arr.end(), totalsum);
    
/* if((totalsum - amount) % 2 != 0 || totalsum - amount < 0) return -1; // impossible to solve */
    if((totalsum + amount) % 2 != 0 ) return -1; // impossible to solve

/* int target = (totalsum - amount)/2; */
    int target = (totalsum + amount)/2;
    vector<int> cur(target+1, 0), prev(target+1, 0);

    if(arr[0] == 0){
        prev[0] = 2; //taken and not taken will result in same output for anmount = 0
    }
    else{
        prev[0] = 1;// to not take anything since amount = 0
    }

    if(arr[0] != 0 && arr[0] <= target){
        prev[arr[0]] = 1; // when amount = arr[0] then it can definitely be picked
    }

    for (int i  = 1; i < n; i++) {
        for (int T = 0; T <= target; T++) {
            int nottake = prev[T];
            int take = 0;
            if(arr[i] <= T){
                take = prev[T - arr[i]];
            }
            cur[T] = take + nottake;
        } 
        prev = cur;
    }
    return prev[target];
}


int main(){
    vector<int> arr = {1,2,3,1};
    int target = 3;
    cout << noofwaystoachievetarget(arr, target) << endl;
    return 0;
}
