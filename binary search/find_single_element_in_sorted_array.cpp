class Solution {
    public:
        int singleNonDuplicate(vector<int>& nums) {
            int n = nums.size(), low = 0, high = n-1;
            //we know n >= 1 and n will always be odd
            while(low <= high){
                int mid = low + (high - low)/2;
                if(mid > 0 && nums[mid-1] == nums[mid]){
                    //if mid was odd meaning (E,O) go right
                    if(mid&1) low = mid+1;
                    //else (O,E) go left
                    else high = mid-1;
                }else if(mid < n-1 && nums[mid+1] == nums[mid]){
                    //if mid was odd then (O,E) go left
                    if(mid&1) high = mid-1;
                    //else (E,O) go right
                    else low = mid+1;
                }else return nums[mid];//found the single element
    
            }
            return -1;
        }
    };