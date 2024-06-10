
// memoixation
class Solution {
private:
  int f(vector<int> &prices, int ind, bool buy, vector<vector<int>> &dp) {
    if (ind == prices.size())
      return 0;
    if (dp[ind][buy] != -1)
      return dp[ind][buy];
    if (buy) {
      return dp[ind][buy] = max(-prices[ind] + f(prices, ind + 1, false, dp),
                                0 + f(prices, ind + 1, true, dp));
    } else {
      return dp[ind][buy] = max(prices[ind] + f(prices, ind + 1, true, dp),
                                0 + f(prices, ind + 1, false, dp));
    }
  }

public:
  int maxProfit(vector<int> &prices) {
    // only 2 columns per row in dp
    // column 0 is for sell
    // column 1 is for buy
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return f(prices, 0, true, dp);
  }
};

// tabulation
class Solution {

public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    dp[n][0] = dp[n][1] = 0;
    for (int ind = n - 1; ind >= 0; ind--) {
      for (int buy = 0; buy <= 1; buy++) {
        if (buy) {
          dp[ind][buy] = max(-prices[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]);
        } else {
          dp[ind][buy] = max(prices[ind] + dp[ind + 1][1], 0 + dp[ind + 1][0]);
        }
      }
    }
    return dp[0][1]; // since reverse 1 means buy
  }
};

// space optimization

class Solution {

public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    vector<int> cur(2, -1), ahead(2, -1);
    ahead[0] = ahead[1] = 1;
    for (int ind = n - 1; ind >= 0; ind--) {
      for (int buy = 0; buy <= 1; buy++) {
        if (buy) {
          cur[buy] = max(-prices[ind] + ahead[0], 0 + ahead[1]);
        } else {
          cur[buy] = max(prices[ind] + ahead[1], 0 + ahead[0]);
        }
      }
      ahead = cur;
    }
    return ahead[1]; // since reverse 1 means buy
  }
};

// greedy apporach

class Solution {

public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    int profit = 0;
    // greedy
    for (int i = 1; i < n; i++) {
      int buy = prices[i - 1];
      int sell = prices[i];
      if (sell > buy) {
        profit += sell - buy;
      }
    }
    return profit;
  }
};
