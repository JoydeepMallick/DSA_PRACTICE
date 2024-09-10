#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums, int n) {
    int xor1 = 0, xor2 = 0;
    for(int i = 0; i < n-1; i++){
        xor1 ^= (i+1);
        xor2 ^= nums[i];
    }
    xor1 ^= n;
    return xor1^xor2;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 10};
    int n = arr.size();
    cout << "Missing number is: " << missingNumber(arr, n) << endl;
    return 0;
}
