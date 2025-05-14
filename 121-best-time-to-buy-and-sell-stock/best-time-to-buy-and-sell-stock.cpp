class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buytime = prices[0];
        int max_profit = 0;
        for(int i =1 ; i<prices.size();i++)
        {
            int diff = prices[i] - buytime;
            buytime = min(buytime,prices[i]);
            max_profit=max(max_profit,diff);

        }
        return max_profit;
    }
};