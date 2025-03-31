class Solution {
    public:
        int findMin(vector<int>& nums) {
            int n = nums.size();
            int low = 0, high = n-1, minval = INT_MAX;
            while(low <= high){
                int mid = low + (high - low)/2;
                //one section will be sorted and other wont
                //since repeatition exist detection needs to managed for strange case
                if(nums[low]  == nums[mid] && nums[mid] == nums[high]){
                    minval = min( minval, nums[mid] );
                    low++;
                    high--;
                }
    
                //if left section is sorted
                else if(nums[low] <= nums[mid]){
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