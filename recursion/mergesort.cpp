#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int  mid , int high){
    vector<int> temp;
/* [low ... mid] */
/* [mid+1 ... high] */
    int left = low , right = mid+1;// pointers
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    //repair the actual array 
    for(int i = low; i <= high; i++){
        arr[i] = temp[i-low];
    }

}

void MergeSort(vector<int> &arr, int low, int high){
    if(low == high) return;
    int mid = (low + high)/2;
    MergeSort(arr, low, mid);
    MergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

void mergesort(vector<int> &arr, int size){
    MergeSort(arr, 0, size-1);
}

int main(){
    vector<int> arr = {3,1,2,4,1,5,2,6,4};
    mergesort(arr, arr.size());
    for(auto it : arr){
        cout << it << " ";
    }
    return 0;
}
