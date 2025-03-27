class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int n = nums.size();
            int low = 0, high = n-1;
            while(low <= high){
                int mid = low + (high - low)/2;
                if(nums[mid] == target) return mid;
                // left sorted so work on it
                if(nums[mid] >= nums[low]){
                    //target lies in sorted region
                    if(nums[low] <= target && target <= nums[mid]) high = mid-1;
                    //target lies in unsorted region
                    else low = mid+1;
                }
    
                //right sorted so work on it
                else{
                    //target lies in sorted region
                    if(nums[mid] <= target && target <= nums[high]) low = mid+1;
                    //target lies in unsorted region
                    else high = mid-1;
                }
            }
            return -1; //not found
        }
    };