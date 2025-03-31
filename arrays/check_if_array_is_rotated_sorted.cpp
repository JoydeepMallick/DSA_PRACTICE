class Solution {
    public:
        bool check(vector<int>& nums) {
            //array must have atmost 1 cliff
            //[5,6,1,2,3,4] 6 to 1 has a donwfall indicating cliff, since just 1 cliff its ok  to say its rotated sorted
            int n = nums.size();
            int cliffcnt = 0;
            for(int i = 1; i < n; i++){
                if(nums[i] < nums[i-1]) cliffcnt++;
            }
            //check for last and first
            if(nums[n-1] > nums[0]) cliffcnt++;
            if(cliffcnt > 1) return false;
            else return true;
        }
    };