class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();

        //rowWise prefix Sum
        vector<vector<int>>rowCumSum(row,vector<int>(col));
        for(int i=0; i < row ;i++)
        {
             rowCumSum[i][0] =  grid[i][0];
            for(int j =1 ;  j < col ; j++)
            {
                rowCumSum[i][j] =rowCumSum[i][j-1] + grid[i][j];
            }
        }
        //colWise prefix Sum
        vector<vector<int>>ColCumSum(row,vector<int>(col));
       for(int j=0; j< col ;j++)
       {
            ColCumSum[0][j] = grid[0][j];
            for(int i=1; i <row;i++)
            {
                ColCumSum[i][j] = ColCumSum[i-1][j] + grid[i][j];
            }

       }

       //try all possible size square possible from each cell;

       for(int side = min(row,col) ; side >=2 ; side --)
       {

           //check row wise sum same or not

           for(int i =0; i < row -side+1; i++)
           {
                for(int j=0; j<col - side +1 ;j++)
                {
                    int targetSum = rowCumSum[i][j+side-1] - (j >0 ? rowCumSum[i][j-1]: 0);
                    bool allSame= true;

                    for(int k =i+1 ; k < i+side ;k++)
                    {

                        //check row
                        int rowSum = rowCumSum[k][j+side-1] - (j >0 ? rowCumSum[k][j-1]:0) ;
                        if(rowSum != targetSum)
                        {
                            allSame=false;
                            break;
                        }
                            
                    }
                    if(!allSame)
                        continue;

                    // // Check columns
                    

                    for(int c=j ; c < j+side ;c++)
                    {
                        int ColSum = ColCumSum[i+side-1][c] - ( i >0 ? ColCumSum[i-1][c]:0);
                        if(ColSum != targetSum)
                        {
                            allSame=false;
                            break;
                        }
                    }
                    if(!allSame)
                        continue;

                    
                    // Check diagonals
                    int diag =0;
                    int antidiag =0;

                    for(int d=0;d<side;d++)
                    {
                        diag += grid[i+d][j+d];
                        antidiag+= grid[i+d][j+side-d-1];
                    }
                    if(diag == antidiag && antidiag == targetSum)
                        return side;


                }
           }

       }
    return 1;
    }
};