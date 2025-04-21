class Solution {
    public:
        int findKthPositive(vector<int>& arr, int k) {
            int ans = k;
            for(auto ele : arr){
                if(ele <= ans) ans++;
            }
            return ans;
        }
    };