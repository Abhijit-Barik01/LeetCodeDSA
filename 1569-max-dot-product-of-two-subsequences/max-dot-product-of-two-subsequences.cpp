class Solution {
public:
    int n,m;
    int dp[501][501];
    int solve(int i, int j,vector<int>& nums1, vector<int>& nums2 )
    {
        if(i==n || j== m)
            return -1e9;
        if(dp[i][j] != -1e9)
            return dp[i][j];
        int val = nums1[i] * nums2[j];
        int take_i_j  = nums1[i]*nums2[j] + solve(i+1,j+1,nums1,nums2);
        int take_i = solve(i,j+1,nums1,nums2);
        int take_j=solve(i+1,j,nums1,nums2);
        return dp[i][j]=max({val,take_i_j,take_i,take_j});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        n = nums1.size();
        m = nums2.size();
        for(int i =0;i<n;i++)
        {
            for(int  j=0;j<m;j++)
            {
                dp[i][j] = -1e9;
            }
        }

        return solve(0,0,nums1,nums2);

    }
};