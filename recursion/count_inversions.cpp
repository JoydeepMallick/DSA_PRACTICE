#include <bits/stdc++.h>
using namespace std;

void printarr(vector<int> &arr){
    for(auto it : arr){
        cout << it << " ";
    }
    cout << endl;
}

/*
 avoid using count as global varible in interviews since it kinds make data security bleak.

 */


int merge(vector<int> &arr, int low, int mid, int high){
    vector<int> tmp;
    int left = low;
    int right = mid+1;
    int cnt = 0;

    while(left <= mid && right <= high){
        if(arr[left] < arr[right]){
            tmp.push_back(arr[left]);
            left++;
        }
        //since right is smaller than left hence inversion pairs possible
        else{
            tmp.push_back(arr[right]);
            right++;
            cnt += (mid - left + 1);
        }
    }

    //insert remaining in tmp array
    while(left <= mid) tmp.push_back(arr[left++]);
    while(right <= high) tmp.push_back(arr[right++]);


    //update actual array in place
    for(int i = low; i <= high; i++){
        arr[i] = tmp[i-low];
    }

    return cnt;
}

int mergesort(vector<int> &arr, int low, int high){
    int cnt = 0;
    if(low < high){
        int mid = (low + high)/2;
        cnt += mergesort(arr, low, mid);
        cnt += mergesort(arr, mid+1, high);
        cnt += merge(arr,low, mid, high);
    }
    return cnt;
}

int countinversions(vector<int> &arr){
    int n = arr.size();
    int cnt = mergesort(arr, 0, n-1);
    return cnt;
}

int main(){
    vector<int> arr = {5,3,2,4,1}; // ans = 8
    
    cout << countinversions(arr) << endl;
}


//try similar problem on global and local inversions leetcode but here observation would be the key since the problem can be solved more easily than expected
//
//https://leetcode.com/problems/global-and-local-inversions/solutions/113644/c-java-python-easy-and-concise-solution/
