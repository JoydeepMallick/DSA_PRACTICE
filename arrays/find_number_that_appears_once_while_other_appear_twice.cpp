#include <bits/stdc++.h>
using namespace std;

int findnumber(vector<int> &arr){
    int n = arr.size(), xorval = 0;
    for (int i = 0; i < n; i++) {
        xorval ^= arr[i];
    }
    return xorval;
}
int getSingleElement(vector<int> &arr){
    int ans = 0;
    for(int i=1;i<arr.size();i = i+2){
        if(arr[i-1]!= arr[i]){
            ans = arr[i-1];
            return ans;
        }
    }
    return arr[arr.size()-1];
}
int main(){
    vector<int> arr = {1,2,1,3,3,5,4,4,5};
    cout << findnumber(arr) << endl;
    return 0;
}
