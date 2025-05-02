#include <limits.h>

int kthElement(vector<int> &arr1, vector<int>& arr2, int n1, int n2, int k){

    if(n1 > n2) return kthElement(arr2, arr1, n2, n1, k);
    int low = max(0, k-n2), high = min(n1, k);
    
    while(low <= high){
        int mid1 = (low + high)/2;
        int mid2 = k - mid1; // try to maintain k elements on left
        int l1 = (mid1-1 >= 0) ? arr1[mid1-1] : INT_MIN;
        int l2 = (mid2-1 >= 0) ? arr2[mid2-1] : INT_MIN;
        int r1 = (mid1 < n1) ? arr1[mid1] : INT_MAX;
        int r2 = (mid2 < n2) ? arr2[mid2] : INT_MAX;
        if(l1 <= r2 && l2 <= r1){
            //sorted state
            return max(l1, l2);
        }else if(l1 > r2){
            high = mid1-1;
        }else{
            low = mid1+1;
        }
    }
    return 0;
}