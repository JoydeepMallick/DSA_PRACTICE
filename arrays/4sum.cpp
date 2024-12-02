#include<bits/stdc++.h>
using namespace std;
// better approach
vector<vector<int>> fourSum(vector<int>& arr, int target) {
    int n = arr.size();
    set<vector<int>> uniquequad;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            set<int> hashset;
            int k = j+1;
            while(k < n){
                int arrl = target - (arr[i] + arr[j] + arr[k]);
                if(hashset.find(arrl) != hashset.end()){
                    vector<int> tmp = {arr[i], arr[j], arr[k], arrl};
                    sort(tmp.begin(), tmp.end());
                    uniquequad.insert(tmp);
                }
                hashset.insert(arr[k]);
                k++;
            }
        }
    }
    vector<vector<int>> ans(uniquequad.begin(), uniquequad.end());
    return ans;
}


//optimal approach
vector<vector<int>> fourSum(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    
    for(int i = 0; i < n; i++){
        if(i > 0 && arr[i] == arr[i-1]) continue;
        for(int j = i+1; j < n; j++){
            if(j > i+1 && arr[j] == arr[j-1]) continue;
            int k = j+1;
            int l = n-1;
            while(k < l){
                long long s = arr[i] + arr[j] + arr[k] + arr[l];
                if(s == target){
                    ans.push_back({arr[i], arr[j], arr[k], arr[l]});
                    k++;l--;
                    while(k < l && arr[k]==arr[k-1]) k++;
                    while(l > k && arr[l]==arr[l+1]) l--;
                } 
                else if(s > target){
                    l--;
                }else if(s < target){
                    k++;
                }
            }
        }
    }
    
    return ans;
}
