class Solution {
public:
 typedef long long ll;
  int n;
  ll dp[100000][2];

    long long solve(int idx,vector<int>&nums,bool flag)
    {
        if(idx >=n)
            return 0;

        if(dp[idx][flag]!= -1)
        {
            return dp[idx][flag];
        }

        ll skip = solve(idx+1,nums,flag);
        ll val = nums[idx];

        if(flag == false)
        {
            val = -val;
        }

        ll take = solve(idx+1,nums,!flag)+val;

        return dp[idx][flag] = max(skip,take);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        n= nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,nums,true);
        
    }
};