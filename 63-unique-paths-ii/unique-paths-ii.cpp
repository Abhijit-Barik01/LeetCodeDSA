class Solution {
public:
vector<vector<int>>dp;
    int solve(vector<vector<int>>& obstacleGrid,int m ,int n , int i,int j)
    {
        if(i>=m || j >= n)
            return 0;

        if(dp[i][j] !=-1)
            return dp[i][j];
         if(obstacleGrid[i][j] ==1)
            return 0;
        if(i == m-1 && j == n-1)
            return 1;
        
       
        return dp[i][j] = solve(obstacleGrid,m,n,i+1,j)+solve(obstacleGrid,m,n,i,j+1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        dp.assign(m+1, vector<int>(n+1,-1));
        return solve(obstacleGrid,m,n,0,0);
    }
};