class Solution {
    public:
        int smallestsum(vector<int> &nums, int d){
            int s = 0;
            for(auto ele : nums){
                s += ceil(ele/(double)d);
            }
            return s;
        }
    
        int smallestDivisor(vector<int>& nums, int threshold) {
            int n = nums.size();
            if(threshold < n) return -1;
    
            int low = 1;
            int high = *max_element(nums.begin(), nums.end());
    
            while(low <= high){
                int mid = low + (high - low)/2;
                if(smallestsum(nums, mid) <= threshold){
                    high = mid-1;//find a more smaller ans if possible
                }else{
                    low = mid+1;
                }
            }
            return low;
        }
    };