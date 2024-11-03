class Solution {
public:
int dp[1001][1001];
int n;
int lis(vector<vector<int>>& pairs, int curr, int prev)
{
    if(curr >= n )
        return 0;
     if( prev != -1 && dp[curr][prev] != -1)
        return dp[curr][prev];
    int taken=0;
    if (prev == -1 || pairs[curr][0] > pairs[prev][1] ) 
    {
         taken =1+lis(pairs,curr+1,curr);
    }
    int nottaken =lis(pairs,curr+1,prev);
    if(prev != -1)
    {
        dp[curr][prev]=max(taken,nottaken);
    }
    return max(taken,nottaken);
}
    int findLongestChain(vector<vector<int>>& pairs) {
        n = pairs.size();
        memset(dp,-1,sizeof(dp));
        sort(pairs.begin(),pairs.end());
        return lis(pairs,0,-1);
    }
};