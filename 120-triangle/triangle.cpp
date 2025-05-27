class Solution {
public:
    vector<vector<int>>dp;
    int minimumPathSum(int row,int col,vector<vector<int>>& triangle)
    {
        if(row == triangle.size()-1)
        {
            return triangle[row][col];
        }
        if(dp[row][col] != -1)
            return dp[row][col];
        int down = minimumPathSum(row+1,col,triangle);
        int diagonal =minimumPathSum(row+1,col+1,triangle);
        return dp[row][col] = triangle[row][col] + min(down,diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        dp.assign(n, vector<int>(n,-1));
        return minimumPathSum(0,0,triangle);  
    }
};