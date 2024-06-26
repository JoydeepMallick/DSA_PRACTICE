//memoization
class Solution {
private:
    int f(vector<int> &prices, int ind, bool buy, int cap, vector<vector<vector<int>>> &dp){
        if(cap == 2) return 0;
        if(ind == prices.size()) return 0;
        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        int profit = 0;
        if(buy){
            profit = max(
                -prices[ind] + f(prices,ind+1, false, cap, dp),
                0 + f(prices,ind+1, true, cap, dp)
            );
        }else{
            profit = max(
                prices[ind] + f(prices,ind+1, true, cap+1, dp),
                0 + f(prices,ind+1, false, cap, dp)
            );
        }
        return dp[ind][buy][cap] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(2, -1)));
        return f(prices, 0, true, 0, dp);
    }
};



//tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));
        //base cases
        for(int ind = 0; ind <= n; ind++){
            for(int buy = 0; buy <= 1; buy++){
                dp[ind][buy][2] = 0;
            }
        }
        for(int buy = 0; buy <= 1; buy++){
            for(int transcnt = 0; transcnt <= 1; transcnt++){
                dp[n][buy][transcnt] = 0;
            }
        }
        //loop
        for(int ind = n-1; ind >= 0; ind--){
            for(int buy = 0; buy <= 1; buy++){
                for(int transcnt = 1; transcnt >= 0; transcnt--){
                    int profit = 0;
                    if(buy){
                        profit = max(
                            -prices[ind] + dp[ind+1][false][transcnt],
                            0 + dp[ind+1][true][transcnt]
                        );
                    }else{
                        profit = max(
                            prices[ind] + dp[ind+1][true][transcnt+1],
                            0 + dp[ind+1][false][transcnt]
                        );
                    }
                    dp[ind][buy][transcnt] = profit;
                }
            }
        }
        return dp[0][true][0];
    }
};



//space optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //base cases are all initialized to 0
        vector<vector<int>> cur(2, vector<int>(3, 0)), after(2, vector<int>(3, 0));
                
        //loop
        for(int ind = n-1; ind >= 0; ind--){
            for(int buy = 0; buy <= 1; buy++){
                for(int transcnt = 1; transcnt >= 0; transcnt--){
                    int profit = 0;
                    if(buy){
                        profit = max(
                            -prices[ind] + after[false][transcnt],
                            0 + after[true][transcnt]
                        );
                    }else{
                        profit = max(
                            prices[ind] + after[true][transcnt+1],
                            0 + after[false][transcnt]
                        );
                    }
                    cur[buy][transcnt] = profit;
                }
            }
            after = cur;
        }
        return after[true][0];
    }
};

//GREEDY
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int firstbuy = INT_MAX, secondbuy = INT_MAX, firstsellprof = 0, secondsellprof = 0;
        for(int i = 0; i < n ; i++){
            firstbuy = min(firstbuy, prices[i]);
            firstsellprof = max(firstsellprof, - firstbuy + prices[i]);
            secondbuy = min(secondbuy, prices[i] - firstsellprof  );//second buy costs less than actual price as we made a profit and can use that money
            secondsellprof = max(secondsellprof, -secondbuy + prices[i]);
        }
        return secondsellprof;
    }
};