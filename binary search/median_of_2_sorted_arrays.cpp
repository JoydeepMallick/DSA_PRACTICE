
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