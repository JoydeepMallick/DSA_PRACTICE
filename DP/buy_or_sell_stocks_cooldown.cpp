//memoization
class Solution {
private:
    int f(vector<int> &prices, int ind, int buy, vector<vector<int>> &dp){
        if(ind >= prices.size()) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        int profit = 0;
        if(buy){
            profit = max(-prices[ind] + f(prices, ind+1, 0, dp), f(prices, ind+1, 1, dp));
        }else{
            profit = max(prices[ind] + f(prices, ind+2, 1, dp), f(prices, ind+1, 0, dp));
        }
        return dp[ind][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(prices, 0, 1, dp);
    }
};

//tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0));//base case initalized all to 0
        for(int ind = n-1; ind >= 0; ind--){
            for(int buy = 0; buy <= 1; buy++){
                int profit = 0;
                if(buy){
                    profit = max(-prices[ind] + dp[ind+1][0], dp[ind+1][1]);
                }else{
                    profit = max(prices[ind] + dp[ind+2][1], dp[ind+1][0]);
                }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }
};

//modified tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0));//base case initalized all to 0
        for(int ind = n-1; ind >= 0; ind--){
            dp[ind][1] = max(-prices[ind] + dp[ind+1][0], dp[ind+1][1]);
            dp[ind][0] = max(prices[ind] + dp[ind+2][1], dp[ind+1][0]);
        }
        return dp[0][1];
    }
};

//space optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> cur(2, 0), ahead1(2, 0), ahead2(2, 0);//base case initalized all to 0
        for(int ind = n-1; ind >= 0; ind--){
            cur[1] = max(-prices[ind] + ahead1[0], ahead1[1]);
            cur[0] = max(prices[ind] + ahead2[1], ahead1[0]);

            ahead2 = ahead1;
            ahead1 = cur;
        }
        return ahead1[1];
    }
};