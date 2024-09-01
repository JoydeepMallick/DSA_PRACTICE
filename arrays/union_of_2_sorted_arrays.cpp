#include <bits/stdc++.h>
using namespace std;

vector<int> arrayUnion(vector<int> &arr1, vector<int> &arr2){
    vector<int> unionarr;
    int n1 = arr1.size();
    int n2 = arr2.size();
    int i = 0, j = 0;
    while(i < n1 && j < n2){
        if(arr1[i] <= arr2[j]){
            if(unionarr.empty() || unionarr.back() != arr1[i]){
                unionarr.push_back(arr1[i]);
            }
            i++;
        }else{
            if(unionarr.empty() || unionarr.back() != arr2[j]){
                unionarr.push_back(arr2[j]);
            }
            j++;
        }
    }
    while(i < arr1.size()){
        if(unionarr.empty() || unionarr.back() != arr1[i]){
            unionarr.push_back(arr1[i]);
        }
        i++;
    }
    while(j < arr2.size()){
        if(unionarr.empty() || unionarr.back() != arr2[j]){
            unionarr.push_back(arr2[j]);
        }
        j++;
    }
    return unionarr;
}

int main(){
    vector<int> arr1 = {1, 1, 2, 3, 4, 5};
    vector<int> arr2 = {2, 3, 4, 4, 5, 6};
    cout << "Array after union: ";
    for(auto ele : arrayUnion(arr1, arr2)){
        cout<<ele<<" ";
    }
    return 0;
}
