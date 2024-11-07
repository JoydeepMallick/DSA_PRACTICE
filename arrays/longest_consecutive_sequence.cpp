#include <bits/stdc++.h>
using namespace std;

int longest_consecutive_sequence_optimal(vector<int> &arr){
    int n = arr.size();
    unordered_set<int> s;
    for(int i = 0; i < arr.size(); i++){
        s.insert(arr[i]);
    }
    int longest = 0;
    for(auto ele : s){
        if(s.find(ele-1) == s.end()){
            int cnt = 0;
            while(s.find(ele) != s.end()){
                ele++;
                cnt++;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}


int longest_consecutive_sequence(vector<int> &arr){
    sort(arr.begin(), arr.end());
    int longest = 0, curlength = 0, prevval = INT_MIN;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i]-1 == prevval){
            curlength++;
            prevval = arr[i];
        }else if(arr[i] != prevval){
            curlength = 1;//reset the length
            prevval = arr[i];
        }
        longest = max(longest, curlength);
    }
    return longest;
}

int main(){
    vector<int> arr = {102, 4, 100, 1, 101, 3, 2, 1, 1};
    cout << longest_consecutive_sequence(arr) << endl;
    cout << longest_consecutive_sequence_optimal(arr) << endl;
    return 0;
}
