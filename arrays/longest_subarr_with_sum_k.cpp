#include <bits/stdc++.h>
using namespace std;

void dbg(unordered_map<long long, int> &prefSumMap){
    cout << "\n{ ";
    for(auto it = prefSumMap.begin(); it != prefSumMap.end(); it++){
        cout << "{ " << it->first << ":" << it->second << " }";
    }
    cout << " }\n";
}


//valid only for positives and zeros 
int longestSubarrayWithSumK_nonegatives(vector<int> &arr, int k){
    int n = arr.size();
    int lp = 0, rp = 0,  maxLen = 0;
    long long sum = arr[0];
    while(rp < n){
        //shift left pointer wherever current sum exceeds k
        while(lp <= rp && sum > k){
            sum -= arr[lp];
            lp++;
        }
        if(sum == k){
            maxLen = max(maxLen, rp - lp +1);
        }
        rp++;
        if(rp < n){
            sum += arr[rp];
        }
    }
    return maxLen;
}

// valid for positives, negatives and zeros
int longestSubarrayWithSumK(vector<int> &arr, int n, int k){
    unordered_map<long long, int> prefSumMap;
    int prefSum = 0, maxLen = 0;
    for(int i = 0; i < n; i++){
        prefSum += arr[i];
        if(prefSum == k){
            maxLen = max(i+1, maxLen);
        }
        else if(prefSumMap.find(prefSum - k) != prefSumMap.end()){
            maxLen = max(i - prefSumMap[prefSum - k], maxLen);
        }

        if(prefSumMap.find(prefSum) == prefSumMap.end()){
            prefSumMap[prefSum] = i;//only if key not found, ensures that the first occurence of the sum is stored and hence we get longest subarray like in cases arr = {2,0,0,3} and k = 3 then ans = 3
        }
/* dbg(prefSumMap); */
    }
    return maxLen;
}

int main(){
    int n = 10, k = 3;
    vector<int> arr = {1,2,3,1,1,1,1,4,2,3};
    cout << "Longest subarray with sum " << k << " is: " << longestSubarrayWithSumK(arr, n, k) << ", " << longestSubarrayWithSumK_nonegatives(arr, k) <<   endl;
    vector<int> arr2 = {2,0, 0, 3};
    k = 3, n = 4;
    cout << "Longest subarray with sum " << k << " is: " << longestSubarrayWithSumK(arr2, n, k) << ", " << longestSubarrayWithSumK_nonegatives(arr2, k) << endl;
    vector<int> arr3 = {2,0,0,3,-1,-2,3};
    k = 3, n = 7;
    cout << "Longest subarray with sum " << k << " is: " << longestSubarrayWithSumK(arr3, n, k) << endl;
    return 0;
}
