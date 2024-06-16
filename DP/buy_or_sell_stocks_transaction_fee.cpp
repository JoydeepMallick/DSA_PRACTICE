//memoization
class Solution{
private:
    int f(vector<int> &prices, int ind, int buy, int fee, vector<vector<int>> &dp){
        if(ind >= prices.size()) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        int profit = 0;
        if(buy){
            profit = max(-prices[ind] + f(prices, ind+1, 0, fee, dp), f(prices, ind+1, 1, fee, dp));
        }else{
            profit = max(prices[ind] - fee + f(prices, ind+1, 1, fee, dp), f(prices, ind+1, 0, fee, dp));
        }
        return dp[ind][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(prices, 0, 1, fee, dp);
    }
};	

//tabulation
class Solution{
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        for(int ind = n-1; ind >= 0 ; ind--){
            dp[ind][1] = max(-prices[ind] + dp[ind+1][0], dp[ind+1][1]);
            dp[ind][0] = max(prices[ind] - fee + dp[ind+1][1], dp[ind+1][0]);
        }
        return dp[0][1];
    }
};