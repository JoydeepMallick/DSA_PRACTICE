class Solution {
public:
    bool validMountainArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dpLIS(n, 1), dpLDS(n, 1);
        //LIS
        for(int i = 1; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[i] > nums[prev]){
                    dpLIS[i] = max(dpLIS[i], 1 + dpLIS[prev]);
                }
            }
        }
        //LDS
        for(int i = n-2; i >= 0; i--){
            for(int next = n-1; next > i; next--){
                if(nums[i] > nums[next]){
                    dpLDS[i] = max(dpLDS[i], 1 + dpLDS[next]);
                }
            }
        }

        int bitoniclength = 0;
        for(int i=0; i < n; i++){
            if(dpLIS[i]==1 || dpLDS[i]==1) continue;
            bitoniclength = max(bitoniclength, dpLIS[i] + dpLDS[i] - 1);
        }
        
        return n == bitoniclength;
    }
};