class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = prices[0], maxprofit = 0;//worst case when stock prices goes on reducing with time hence no need to buy and sell
        for(int i = 1; i < n; i++){
            int sell = prices[i];
            int profit = sell - buy;
            maxprofit = max(maxprofit, profit);
            buy = min(buy, prices[i]);
        }
        return maxprofit;
    }
};