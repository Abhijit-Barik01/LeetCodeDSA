class Solution {
public:
    bool solve(vector<int>& nums, int n, int idx, vector<int>& dp) {
        if (idx >= n - 1) return true;
        if (dp[idx] != -1) return dp[idx];

        for (int jump = 1; jump <= nums[idx]; ++jump) {
            if (solve(nums, n, idx + jump, dp)) {
                return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }

    bool solveBottomUp(vector<int>& nums, int n, vector<bool>& dp)
    {
        dp[n-1]= 1;

        for(int i = n-2 ; i>=0 ;i--)
        {
            int maxjump= nums[i];

            for(int j = 1 ;j<= maxjump && i + j < n; ++j)
            {
                if (dp[i+j])
                {
                    dp[i]= true;
                    break;
                }
            }
        }
     return dp[0];
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false); // dynamic dp with size n initialized to -1
          return solveBottomUp(nums,n,dp);



        //return solve(nums, n, 0, dp);
    }
};