
// brute with optimzed space
class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int n1 = nums1.size(), n2 = nums2.size();
            int n = n1+n2;
            //indices needed
            int needind1 = n/2, needind2 = n/2-1;
            int mergedind = 0;
            int i = 0, j = 0;
            int val1 = -1, val2 = -1;
            while(i < n1 && j < n2){
                if(nums1[i] < nums2[j]){
                    if(mergedind == needind1) val1 = nums1[i];
                    if(mergedind == needind2) val2 = nums1[i]; 
                    i++;
                }else{
                    if(mergedind == needind1) val1 = nums2[j];
                    if(mergedind == needind2) val2 = nums2[j]; 
                    j++;
                }
                mergedind++;
            }
            while(i < n1){
                if(mergedind == needind1) val1 = nums1[i];
                if(mergedind == needind2) val2 = nums1[i]; 
                i++; mergedind++;
            }
    
            while(j < n2){
                if(mergedind == needind1) val1 = nums2[j];
                if(mergedind == needind2) val2 = nums2[j]; 
                j++; mergedind++;
            }
    
            if(n&1){
                return val1;
            }else{
                return (val1+val2)/2.0;
            }
        }
    };


    // binary search
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);//smaller array is considered for partition for lesser calculations

        int n = n1+n2;
        int low = 0, high = n1;
        while(low <= high){
            int mid1 = (low + high)/2; 
            int mid2 = n/2 - mid1; // or int mid2 = (n+1)/2 - mid1;
            int l1 = (mid1 - 1 >= 0) ? nums1[mid1-1] : INT_MIN, 
                l2 = (mid2 - 1 >= 0) ? nums2[mid2-1] : INT_MIN;
            int r1 = (mid1 < n1) ? nums1[mid1] : INT_MAX, 
                r2 = (mid2 < n2) ? nums2[mid2] : INT_MAX;
            if(l1 <= r2 && l2 <= r1){
                if(n&1){
                    //left side has lesser elements
                    return min(r1,r2); // or max(l1,l2)
                }else{
                    return (double)(max(l1,l2) + min(r1,r2))/2.0;
                }
            }else if(l1 > r2){
                high = mid1-1;
            }else{
                low = mid1+1;
            } 
        }
        return 0;
    }
};
