#include <bits/stdc++.h>
using namespace std;

string getPermutation(int n, int k){
    int fact = 1;
    vector<int> num;
    for(int i =1; i < n; i++){
        fact *= i;
        num.push_back(i);
    }
    num.push_back(n);

    string ans = "";
    k--;// oth indexing 
    while(1){
        ans += to_string(num[k/fact]);
        num.erase(num.begin() + k/fact);
        if(num.size() == 0){
            break;
        }
        k = k % fact;
        fact /= num.size();
    }
    return ans;
}

int main(){
    int n = 4, k = 17;
    cout << getPermutation(n,k) << endl;
}
