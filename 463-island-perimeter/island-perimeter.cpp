class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 2*(1+1);
        int up,down,left,right;
        int row = grid.size();
        int col = grid[0].size();
        int result = 0;

        for(int i=0; i<grid.size();i++)
        {
            for(int j=0; j<grid[i].size();j++)
            {
                if(grid[i][j] ==1)
                {
                    if(i== 0)
                    {
                        up = 0;
                    }
                    else
                    {
                        up = grid[i-1][j];
                    }
                    if(j ==0 )
                        left =0;
                    else
                        left =grid[i][j-1];
                    
                    if(j == col-1 )
                        right =0;
                    else
                        right=grid[i][j+1];
                    if(i==row-1)
                        down = 0;
                    else
                         down =grid[i+1][j];
                    result+=perimeter-(up+left+right+down);

                }
            }
        }
        return result;
    }
};