class Solution {
public:
    vector<string>ColumnState;
    const int MOD = 1e9+7;
    vector<vector<int>>dp;
    void generateFirstColumnAllPossibleStringCom(string Curr, char prevColour, int l , int m ) {
        if(l == m)
        {
            ColumnState.push_back(Curr);
            return ;
        }

         for(char ch :{'R','G','B'})
         {
            if(ch == prevColour )
                continue;
           generateFirstColumnAllPossibleStringCom(Curr+ch,ch ,l+1,m) ;
         }
    }

    int solve(int prevIndex, int remainingColumnLenToFill,int m)
    {
        if( dp[remainingColumnLenToFill][prevIndex] != -1)
            return dp[remainingColumnLenToFill][prevIndex];

        if(remainingColumnLenToFill == 0)
            return 1;

        int totalways =0 ;

        string PreviousColumn= ColumnState[prevIndex];

        for(int nextColumnStringIdx =0; nextColumnStringIdx < ColumnState.size(); nextColumnStringIdx++  )
        {
            if(prevIndex== nextColumnStringIdx)
                    continue;
            
            string nextColumnString= ColumnState[nextColumnStringIdx];

            bool flag = true;

            for(int i=0 ;i <m;i++)
            {
                if(nextColumnString[i] == PreviousColumn[i] )
                {
                    flag = false;
                    break;
                }
            }
            if(flag) 
            {
                totalways= (totalways +solve(nextColumnStringIdx,remainingColumnLenToFill -1,m))%MOD;
            }
        }
        return dp[remainingColumnLenToFill][prevIndex]=totalways;
    }
    int colorTheGrid(int m, int n) {

         //fix row because row value is fix thats why we fill first column first  
         generateFirstColumnAllPossibleStringCom("",'#',0,m);
         int numColStateLength = ColumnState.size();
         dp.assign(n,vector<int>(numColStateLength,-1));

         
         int result = 0;

         for(int i =0; i < numColStateLength ; i++)
         {
            result = (result + solve(i,n-1,m))%MOD;
         }

        return result;
    }
};