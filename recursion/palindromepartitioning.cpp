#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int start, int end){
    while(start <= end){
        if(s[start++] != s[end--]) return false; 
    }
    return true; 
}

void func(int ind, string s, vector<string> &path, vector<vector<string>> &res){
    if(ind == s.size()){
        res.push_back(path);
        return; 
    }

    for(int i = ind; i<s.size(); ++i){
        if(isPalindrome(s, ind, i)){
            path.push_back(s.substr(ind, i - ind + 1));
            func(i+1, s, path, res);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s){
    vector<vector<string>> res;
    vector<string> path;
    func(0, s, path, res);
    return res;
}

int main(){
    string s1 = "aab", s2 = "aabb";
    vector<vector<string>> ans1, ans2;

    ans1 = partition(s1);
    ans2 = partition(s2);

    for(auto it : ans1){
        cout << "[ ";
        for(auto it2 : it) cout << it2 << " ";
        cout << "] ";
    }

    cout << "\n\n";
    for(auto it : ans2){
        cout << "[ ";
        for(auto it2 : it) cout << it2 << " ";
        cout << "] ";
    }
}
