class Solution {
public:
    int robbing(vector<int>&nums,vector<int>&dp,int i)
    {
        if(i >=nums.size())
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        int rob1= nums[i] + robbing(nums,dp,i+2);
        int rob2= robbing(nums,dp,i+1);
        int ans = max(rob1,rob2);
        return dp[i] =ans;

    }
    int rob(vector<int>& nums) {
        vector<int>dp(101,-1);

        return robbing(nums,dp,0);
        
    }
};