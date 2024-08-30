#include <bits/stdc++.h>
#include <vector>
using namespace std;

void leftrotate(vector<int> &a, int n, int d){
    d = d%n;
    vector<int> tmp;
    for(int i = 0; i < d; i++){
        tmp.push_back(a[i]);
    }
    //shift by d
    for(int i = d; i < n; i++){
        a[i-d] = a[i];
    }
    //placing rest
    for(int i = n-d; i < n; i++){
        a[i] = tmp[i - (n-d)];
    }
}


void leftrotate_noextraspace(vector<int> &a, int n, int d){
    d = d%n;
    reverse(a.begin(), a.begin() + d);
    reverse(a.begin() + d, a.end());
    reverse(a.begin(), a.end());
}

int main(){
    vector<int> a = {1,2,3,4,5,6,7};
    int n = 7, d = 3;
    leftrotate(a, n, d);
    for(auto ele : a)cout << ele << " ";
    cout << endl;
    vector<int> b = {1,2,3,4,5,6,7, 8, 9};
    n = 9;
    leftrotate_noextraspace(b, n, d);
    for(auto ele : b)cout << ele << " ";
    cout << endl;
    return 0;
}
