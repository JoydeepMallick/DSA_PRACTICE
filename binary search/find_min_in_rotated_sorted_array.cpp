class Solution {
    public:
        int findMin(vector<int>& nums) {
            int minval = INT_MAX;
            int n = nums.size();
            int low = 0, high = n-1;
            while(low <= high){
                int mid = low + (high - low)/2;
                // if entire search space is sorted
                if(nums[low] <= nums[high]){
                    minval = min(minval, nums[low]);
                    break;
                }
    
                //if left section is sorted
                if(nums[low] <= nums[mid]){
                    minval = min(minval, nums[low]);
                    low = mid+1;
                }
                //right section is sorted
                else{
                    minval = min(minval, nums[mid]);
                    high = mid-1;
                }
            }
            return minval;
        }
    };