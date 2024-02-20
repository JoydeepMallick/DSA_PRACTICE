#include <bits/stdc++.h>
using namespace std;

void findPerm(int ind, vector<int> &num, vector<vector<int>> &ans ){
    if(ind == (int)num.size()){
        ans.push_back(num);
        return;
    }

    for(int i = ind; i < (int)num.size(); i++){
        swap(num[ind], num[i]);
        findPerm(ind+1, num, ans);
        swap(num[ind], num[i]);// rearrange to original position after above function call is done 
    }
}

vector<vector<int>> Permutations(vector<int> num){
    vector<vector<int>> ans;
    findPerm(0, num, ans);
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


