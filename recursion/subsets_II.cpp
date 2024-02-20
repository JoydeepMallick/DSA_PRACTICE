#include <bits/stdc++.h>
using namespace std;

void findSubsets(int n, int ind, vector<int> &num, vector<int> &sub, vector<vector<int>> &ans){
    ans.push_back(sub); // insert the subset 
    for(int i = ind; i < n; i++ ){
        if(i!=ind && num[i] == num[i-1]) continue;
        sub.push_back(num[i]);
        findSubsets(n, i+1, num, sub, ans);
        sub.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(int N, vector<int> num){
    sort(num.begin(), num.end());
    vector<int> sub;
    vector<vector<int>> ans;
    findSubsets(N, 0, num, sub, ans);
    return ans;
}

int main(){
    vector<int> nums = {1,2,2,2,3,3};
    int n = 6;
    for(auto it :subsetsWithDup(n, nums)){
        cout << " [ ";
        for(auto it2 : it) cout << it2 <<",";
        cout << "\b ] ";
    }
    return 0;
}
