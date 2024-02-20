#include <bits/stdc++.h>
using namespace std;

void findCombination(int ind, vector<int> &candidates, int target, vector<int> &combo, vector<vector<int>> &ans){
    if(target == 0){
        ans.push_back(combo);
        return;
    }

    for(int i = ind; i < (int)candidates.size(); i++){
        if(i > ind && candidates[i] == candidates[i-1]) continue;
        if(candidates[i] > target) break;
        combo.push_back(candidates[i]);

        findCombination(i + 1, candidates, target - candidates[i], combo, ans);

        combo.pop_back();
    }
}

vector<vector<int>> findCombinationSum(vector<int> &candidates, int target){
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> combo;
    findCombination(0, candidates, target, combo, ans);
    return ans;
}

int main(){
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    cout << "[ ";
    for(auto it : findCombinationSum(candidates, target)){
        cout << "[ ";
        for(auto it2 : it){
            cout << it2 << " ";
        }
        cout << "],";
    }
    cout << "\b]\n\n";

    candidates = {2, 5, 2, 1, 2};
    target = 5;
    cout << "[ ";
    for(auto it : findCombinationSum(candidates, target)){
        cout << "[ ";
        for(auto it2 : it){
            cout << it2 << " ";
        }
        cout << "],";
    }
    cout << "\b]\n\n";


    candidates = {1, 1, 1, 2, 2};
    target = 4;
    cout << "[ ";
    for(auto it : findCombinationSum(candidates, target)){
        cout << "[ ";
        for(auto it2 : it){
            cout << it2 << " ";
        }
        cout << "],";
    }
    cout << "\b]\n\n";


    return 0;
}
