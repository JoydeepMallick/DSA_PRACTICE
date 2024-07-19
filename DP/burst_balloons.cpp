//memoization
class Solution {
private:
    int f(vector<int> &nums, int i, int j, vector<vector<int>> &dp){
        if(i > j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int maxcoins = INT_MIN;
        for(int ind = i; ind <= j; ind++){//any one can be picked within range as the kth last element
            int cost = nums[i-1] * nums[ind] * nums[j+1];
            int leftpor = f(nums, i, ind-1, dp);
            int rightpor = f(nums, ind+1, j, dp);

            int totalcoins = cost + leftpor + rightpor;
            maxcoins = max(maxcoins, totalcoins); 
        }
        return dp[i][j] = maxcoins;
    }

public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();//actual size before 1 insertions
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return f(nums, 1, n, dp);
    }
};


//tabulation

class Solution {

public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();//actual size before 1 insertions
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        vector<vector<int>> dp(n+2, vector<int> (n+1, 0)); // handles all base cases 
        for(int i = n; i >= 1; i--){
            for(int j = i; j <= n; j++){
                int maxcoins = INT_MIN;
                for(int ind = i; ind <= j; ind++){//any one can be picked within range as the kth last element
                    int cost = nums[i-1] * nums[ind] * nums[j+1];
                    int leftpor = dp[i][ind-1];
                    int rightpor = dp[ind+1][j];

                    int totalcoins = cost + leftpor + rightpor;
                    maxcoins = max(maxcoins, totalcoins); 
                }
                dp[i][j] = maxcoins;
            }
        }

        return dp[1][n];
    }
};