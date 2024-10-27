#include<bits/stdc++.h>
using namespace std;

vector<int> rearrrangeArray(vector<int> &nums){
    int n = nums.size();
    vector<int> ans(n, 0);
    int posindex = 0, negindex = 1;
    for(int i = 0; i < n; i++){
        if(nums[i] < 0){
            ans[negindex] = nums[i];
            negindex +=2;
        }else{
            ans[posindex] = nums[i];
            posindex +=2;
        }
    }
    return ans;
}

vector<int> rearrange_unequalele(vector<int> &nums){
    int n = nums.size();
    vector<int> ans(n, 0);
    vector<int> pos, neg;
    for(auto ele : nums){
        if(ele < 0) neg.push_back(ele);
        else pos.push_back(ele);
    }
    int minsize = min(pos.size(), neg.size());
    int maxsize = max(pos.size(), neg.size());
    for(int i = 0; i < minsize; i++){
        ans[2*i] = pos[i];
        ans[2*i+1] = neg[i];
    }
    int index = minsize * 2;
    if(pos.size() > neg.size()){
        for(int i = minsize; i < maxsize; i++){
            ans[index] = pos[i];
            index++;
        }
    }else{
        for(int i = minsize; i < maxsize; i++){
            ans[index] = neg[i];
            index++;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {3,1,-2,-5,2,-4};
    cout << "Rearranged elements by sign : ";
    for(auto ele : rearrrangeArray(arr)){
        cout << ele << " ";
    }
    vector<int> arr2 = {3,1,-2,-5,2,-4, 9, 7};
    cout << "Rearranged elements by sign : ";
    for(auto ele : rearrange_unequalele(arr2)){
        cout << ele << " ";
    }
}
