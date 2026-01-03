class Solution {
public:
    vector<string>AllPossibleColorState;
    vector<vector<int>>dp;
    const int MOD = 1e9+7;
    void generateRow(string curr,char prev,int m)
    {
        if(m ==0)
        {
            AllPossibleColorState.push_back(curr);
            return;
        }

       for(char color : {'R','Y','G'})
       {
          if(prev == color)
          {
            continue;
          }
          generateRow(curr+color,color,m-1);
       }
    }
    int solve(int prevIdx, int remainingToFill,int m)
    {
        if(remainingToFill==0)
            return 1;
        
        if(dp[remainingToFill][prevIdx] != -1)
            return dp[remainingToFill][prevIdx];

        int totalways =0;

        string prevStringRow = AllPossibleColorState[prevIdx];

        for(int nextIdxRow =0 ;nextIdxRow < AllPossibleColorState.size(); nextIdxRow++ )
        {
            if(nextIdxRow == prevIdx)
                continue;
            bool valid = true;
            string currStringRow = AllPossibleColorState[nextIdxRow];

            for(int i=0; i<3 ;i++)
            {
               if(prevStringRow[i] == currStringRow[i])
               {
                    valid = false;
                    break;
               }
            }
            if(valid)
            {
                totalways=(totalways+solve(nextIdxRow,remainingToFill-1,m))%MOD;
            }

         
        }
        return dp[remainingToFill][prevIdx]=totalways;
    }
    int numOfWays(int n) {
        generateRow("",'#',3);


        dp.assign(n,vector<int>(AllPossibleColorState.size(),-1));

        int result =0;

        for(int i=0; i<AllPossibleColorState.size();i++)
        {
          result = (result + solve(i,n-1,3))%MOD;
        }

       return result;
    }
};