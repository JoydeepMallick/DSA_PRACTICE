class Solution {
    public:
        int cntsplits(vector<int> &nums, int maxsum){
            int cnt = 1, sum = 0;
            for(int i  = 0; i < nums.size(); i++){
                if(nums[i] + sum <= maxsum){
                    sum += nums[i];
                }else{
                    cnt++;
                    sum = nums[i];
                }
            }
            return  cnt;
        }
    
        int splitArray(vector<int>& nums, int k) {
            if(k > nums.size()) return -1;
    
            int low  = *max_element(nums.begin(), nums.end());
            int high = accumulate(nums.begin(), nums.end(), 0);
            while(low <= high){
                int mid = (low + high)/2;
                int cnt = cntsplits(nums, mid);
                if(cnt <= k) high = mid-1;
                else low = mid+1;
            }
            return low;
        }
    };