class Solution {
public:
   
   int solve(vector<int>& cost,int i ,int n)
   {
        if(i >=n)
            return 0;
        
         return cost[i]+ min(solve(cost, i+1,n) , solve(cost,i+2,n));
        
   }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        //return min (solve(cost, 0,n) , solve(cost,1,n));

        vector<int>dp(n+1,0);
         // Start iteration from step 2, since the minimum cost of reaching
        // step 0 and step 1 is 0
        for(int i =2;i<=n;i++)
        {
           int onestep = dp[i-1] +cost[i-1];

           int  twostep = dp[i-2] + cost[i-2];
            dp[i] = min(onestep,twostep);
        }
        return dp[n];
    }
};