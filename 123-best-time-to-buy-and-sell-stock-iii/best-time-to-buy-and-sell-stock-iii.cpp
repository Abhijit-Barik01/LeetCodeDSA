class Solution {
public:

    int findProfit(vector<int>& prices,int index , int buyflag , int limit , vector<vector<vector<int>>>&dp)
    {
        if(prices.size() == index || limit == 0)
            return 0;
        if(dp[index][buyflag][limit] != -1)
            return dp[index][buyflag][limit];
        int take,nontake;
        if(buyflag)
        {
            take = -prices[index] +findProfit(prices,index+1,0,limit,dp);
            nontake = findProfit(prices,index+1,1,limit,dp);
        }
        else
        {
            take = prices[index] +findProfit(prices,index+1,1,limit-1,dp);
            nontake = findProfit(prices,index+1,0,limit,dp);
        }

        return  dp[index][buyflag][limit]=max(take,nontake);
    }
    int maxProfit(vector<int>& prices) {
     int   n = prices.size();
     vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return findProfit(prices,0,1,2,dp);
        
    }
};