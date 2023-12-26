#include <bits/stdc++.h>
using namespace std;

int opt_idp(vector<int> &arr){
    int n = arr.size();
    int prev = arr[0];
    int prev2;

    for(int i = 1; i < n; i++){
        int pick = arr[i];
        if(i-2 >= 0){
            pick += prev2;
        }

        int notpick = 0 + prev;

        int curi = max(pick, notpick);
        prev2 = prev;
        prev = curi;
    }

    return prev;
}

int maxRobberySum(vector<int> &arr){
    int n = arr.size();
    if(n==1) return arr[0];

    vector<int> temp1, temp2;
    for(int i = 0; i < n; i++){
        if(i!=0) temp1.push_back(arr[i]);
        if(i!=n-1) temp2.push_back(arr[i]);
    }
    return max(opt_idp(temp1),opt_idp(temp2));
}

int main(){
    vector<int> arr = {2,1,4,9}; // ans = 10 
    cout << "max sum of possible money looted : " << maxRobberySum(arr) << endl;
    return 0;
}
