class Solution {
public:
    int findProfit(vector<int>& prices, int index, int buyflag, vector<vector<int>>& dp) {
        if (index >= prices.size()) {
            return 0;
        }

        if (dp[index][buyflag] != -1) {
            return dp[index][buyflag];
        }

        int take, non_take;

        if (buyflag) {
            take = -prices[index] + findProfit(prices, index + 1, 0, dp);  // Buy
            non_take = findProfit(prices, index + 1, 1, dp);               // Skip
        } else {
            take = prices[index] + findProfit(prices, index + 1, 1, dp);   // Sell
            non_take = findProfit(prices, index + 1, 0, dp);               // Skip
        }

        return dp[index][buyflag] = max(take, non_take);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return findProfit(prices, 0, 1, dp);  
        // Start from index 0 with buy flag = 1 (can buy)
    }
};
