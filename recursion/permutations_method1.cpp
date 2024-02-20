
#include <bits/stdc++.h>
using namespace std;

void findPerm(vector<int> &num, vector<int> &perm, vector<vector<int>> &ans, int visind[]){
    if(perm.size() == num.size()){
        ans.push_back(perm);
        return;
    }
    
    for(int i = 0; i < (int)num.size(); i++){
        if(!visind[i]){
            perm.push_back(num[i]);
            visind[i] = 1;
            findPerm(num, perm, ans, visind);
            visind[i] = 0;
            perm.pop_back();
        }
    }
}

vector<vector<int>> Permutations(vector<int> num){
    vector<int> perm;
    vector<vector<int>> ans;
    int visind[num.size()] = {0};

    findPerm(num, perm, ans, visind);
    return ans;
}

int main(){
    vector<int> nums = {1,2,3};
    cout << "All permutations :- ";
    for(auto it : Permutations(nums)){
        cout << " [ ";
        for(auto it2 : it) cout << it2 <<",";
        cout << "\b ] ";
    }
    return 0;
}
