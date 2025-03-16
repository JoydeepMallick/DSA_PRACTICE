#include <bits/stdc++.h>
using namespace std;

// here we return values not indices

//we return the max element if ceil is not possible, -1 handle if needed needs to performed seperately but modifying binary search
int ceilArr(vector<int> arr, int x){
    return *lower_bound(arr.begin(), arr.end(), x) ;
}

// we return -1 incase result not exists
int floorArr(vector<int> arr, int x){
    int low = 0, high = arr.size()-1,  res = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] > x){
            high = mid - 1;
        }else{
            res = arr[mid];
            low = mid + 1;
        }
    }
    return res;
}


int main(){
    vector<int> arr = {10, 25, 30, 40};
    int x = 27;
    cout << ceilArr(arr, x) << endl; // must be index 2 ie.30
    cout << floorArr(arr, x) << endl;// must be index 1 ie.25
}