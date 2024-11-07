#include <bits/stdc++.h>
using namespace std;

vector<int> leaders(vector<int> arr){
    int n = arr.size();
    vector<int> ans;
    int maxtillnow = INT_MIN;
    for(int i = n-1; i >= 0; i--){
        if(arr[i] > maxtillnow){
            maxtillnow = arr[i];
            ans.push_back(maxtillnow);
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {10,22,12,3,0,6};
    for(auto ele : leaders(arr)){
        cout << ele << " ";
    }

    return 0;
}
