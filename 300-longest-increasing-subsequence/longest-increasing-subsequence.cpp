class Solution {
public:
 int n;
 int dp[2502][2502];

    int solve(vector<int>& nums,int curr, int prev)
    {
        if(curr >= n)
            return 0;

        if ( prev !=-1 && dp[curr][prev] !=-1)
        {
            return dp[curr][prev];
        }
int take = 0;
        if(prev ==-1 || nums[curr] > nums[prev])
        {
           take =1+solve(nums,curr+1,curr);
        }

        int skip = solve(nums,curr+1,prev);

        if(prev != -1)
        {
            return dp[curr][prev] = max(take , skip);
        } 

        return max(skip,take);
    }
    int lengthOfLIS(vector<int>& nums) {

        n= nums.size();
        memset(dp,-1,sizeof(dp));



        return solve(nums,0,-1);

        
      
      
    }
};