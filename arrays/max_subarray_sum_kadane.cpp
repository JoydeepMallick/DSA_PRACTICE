#include "bits/stdc++.h"
using namespace std;
// Excluding empty subarray
long long maxSubarraySum_noempty(vector<int> arr, int n)
{
    long long cursum = 0, maxsum = LONG_MIN;
    for(int i = 0; i < n; i++){
        cursum = max(1ll*arr[i], cursum + arr[i]);
        maxsum = max(maxsum, cursum);
    }
    return maxsum;
}

// Including empty subarray
long long maxSubarraySum_empty(vector<int> arr, int n)
{
    long long cursum = 0, maxsum = 0;
    for(int i = 0; i < n; i++){
        cursum = max(0ll, cursum + arr[i]);
        maxsum = max(maxsum, cursum);
    }
    return maxsum;
}

//print start and end indices when non empty only allowed
void maxSubarraySum_range(vector<int> arr, int n)
{
    long long cursum = 0, maxsum = INT_MIN;
    int start  = -1, substart = -1, subend = -1;
    for(int i = 0; i < n; i++){
        if(cursum == 0) start = i;
        cursum += arr[i];
        if(cursum > maxsum){
            maxsum = cursum;
            substart = start;
            subend = i;
        }
        if(cursum < 0) cursum = 0;
    }
    cout << "Start : " << substart << " ,End : " << subend << endl;
}

int main()
{
    int n = 8;
    vector<int> arr = {-2,-3, 4, -1, -2, 1, 5, -3};
    cout << maxSubarraySum_noempty(arr, n) << endl;
    cout << maxSubarraySum_empty(arr, n) << endl;
    maxSubarraySum_range(arr, n);
    n = 4;
    arr = {-4, -2, -1, -4};
    cout << maxSubarraySum_noempty(arr, n) << endl;
    cout << maxSubarraySum_empty(arr, n) << endl;
    maxSubarraySum_range(arr, n);
    return 0;
}
