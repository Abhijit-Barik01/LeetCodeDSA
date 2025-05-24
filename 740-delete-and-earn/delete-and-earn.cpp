class Solution {
public:
    map<int,int>freq;
    vector<int>uniqueNums;
    vector<int>dp;
    int solve(int index)
    {   
      

        if(index >=uniqueNums.size() )
            return 0;
        
         if(dp[index] != -1)
       {
        return dp[index];
       }

        int take = uniqueNums[index]*freq[uniqueNums[index]];

        if(index+1 < uniqueNums.size() && uniqueNums[index+1] == uniqueNums[index] +1 )
        {
            take +=solve(index+2);
        }
        else
        {
            take +=solve(index+1);
        }

        int skip = solve(index+1);

        return dp[index]=max(take,skip);
    }

    int deleteAndEarn(vector<int>& nums) {

        for(auto num: nums)
            freq[num]++;
        for(auto &p: freq)
            uniqueNums.push_back(p.first);
        dp.resize(nums.size()+1, -1);
        
        return solve(0);
        
    }
};