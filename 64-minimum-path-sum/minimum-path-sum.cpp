class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<vector<int>>& grid, int m ,int n,int i , int j )
    {
        if(i>=m || j>=n)
            return INT_MAX;
        if(i == m-1 && j == n-1)
            return grid[i][j] ;
        if(dp[i][j] !=-1)
            return dp[i][j];

        int right = solve(grid,m,n,i,j+1);
        int down = solve(grid,m,n,i+1,j);

        return dp[i][j]=grid[i][j] + min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        dp.assign(m,vector<int>(n,-1));
        return solve(grid,m,n,0,0);

    }
};