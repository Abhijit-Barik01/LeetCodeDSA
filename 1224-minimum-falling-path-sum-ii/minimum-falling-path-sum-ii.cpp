class Solution {
public:
    int arr[201][201];
    int n;

    int solve(int col, int row,vector<vector<int>>& grid)
    {
            if(row == n-1){
                return grid[row][col];
            }

            if(arr[row][col]!= -1)
            {
                return arr[row][col];
            }

        int ans = INT_MAX;

        for( int colNext=0 ; colNext < n; colNext++ )
        {
             if(colNext != col)
             {
                ans= min(ans,solve(colNext,row+1,grid));
             }
        }

        return arr[row][col] = ans + grid[row][col];
    }


    int minFallingPathSum(vector<vector<int>>& grid) {
        memset(arr,-1,sizeof(arr));
        n= grid.size();
        int result = INT_MAX;

        for(int col =0 ; col< n ; col++ )
        {
                result = min(result, solve(col,0,grid));
        }

        return result;
        
    }
};