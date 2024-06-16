//Memoization
class Solution {
private:
    int f(vector<int> &prices, int ind, int buy, int k, vector<vector<vector<int>>> &dp){
        if(k==0) return 0;
        if(ind == prices.size()) return 0;
        if(dp[ind][buy][k] != -1) return dp[ind][buy][k];        
        int profit = 0;
        if(buy){
            profit = max(
                -prices[ind] + f(prices, ind+1, 0, k, dp), 
                0 + f(prices, ind+1, 1, k, dp)
            );
        }else{
            profit = max(
                prices[ind] + f(prices, ind+1, 1, k-1, dp), 
                0 + f(prices, ind+1, 0, k, dp)
            );
        }
        return dp[ind][buy][k] = profit;
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(k+1, -1)));
        return f(prices, 0, 1, k, dp);
    }
};


//tabulation
class Solution {

public:
    int maxProfit(int k, vector<int>& prices) {
        //since all base cases involve 0 lets initialize all the dp values to 0 instead and no need for extra base case intialization
        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        int limit = k, n = prices.size();
        for(int ind = n-1; ind >= 0; ind--){
            for(int buy = 0; buy <= 1; buy++){
                for(int k = 1; k <= limit; k++){
                    int profit = 0;
                    if(buy){
                        profit = max(
                            -prices[ind] + dp[ind+1][0][k], 
                            0 + dp[ind+1][1][k]
                        );
                    }else{
                        profit = max(
                            prices[ind] + dp[ind+1][1][k-1], 
                            0 + dp[ind+1][0][k]
                        );
                    }
                    dp[ind][buy][k] = profit;
                }
            }
        }
        return dp[0][1][k];
    }
};
