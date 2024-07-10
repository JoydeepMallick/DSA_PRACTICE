class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), cnt(n, 1);
        //find those dp[prev] whose value +1 = dp[current index] and sum of cnt[prev] of all those values is answer
        //ensure that dp[current ind] is computed correctly first
        int LISlength = 1;//assuming n >=1
        for(int i = 1; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                //find max dp[i] till prev currently and set cnt[i] to this value and then update cnt[i] whenever similar value hit. If a better value for dp[i] is found again then this will again reset cnt and else part will update it, we can be sure that we do not need to traverse previous indices already visited since we have accounted them in one go 
                if(nums[prev] < nums[i] && dp[prev]+1 > dp[i]){
                    dp[i] = 1 + dp[prev];
                    cnt[i] = cnt[prev];
                }
                //having found max possible dp[i] till now if similar dp[prev] value encountered include it in cnt[i]
                else if(nums[prev] < nums[i] && dp[prev]+1 == dp[i]){
                    cnt[i] += cnt[prev];
                }
            }
            LISlength = max(LISlength, dp[i]);
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] == LISlength){
                ans += cnt[i];
            }
        }
        return ans;
    }
};