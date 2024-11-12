#include <bits/stdc++.h>
using namespace std;


int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int prefsum = 0;
    int cnt = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    for(int i = 0; i < arr.size(); i++){
        prefsum += arr[i];
        int tofind = prefsum - k;
        if(mp.find(tofind) != mp.end()){
            cnt += mp[tofind];
        }
        mp[prefsum]++;
    }
    return cnt;
}

int main(){
    vector<int> arr = {1,2,3,-3,1,1,1,4,2,-3};
    int k = 3;
    cout<<findAllSubarraysWithGivenSum(arr, k);
}
