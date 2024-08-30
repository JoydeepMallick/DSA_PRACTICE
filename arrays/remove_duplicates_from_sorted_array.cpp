#include <bits/stdc++.h>
using namespace std;

int lengthofunique(vector<int> &a, int n){
    int i = 0;
    for(int j = 1; j < n; j++){
        if(a[i] != a[j]){
            a[i+1] =  a[j];
            i++;
        }
    }
    return i+1;
}

int main(){
    vector<int> a = {1,1,2,2,2,3,3};
    cout << lengthofunique(a, 7) << endl;
}
