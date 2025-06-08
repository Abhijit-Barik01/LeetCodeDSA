class Solution {
public:
    int dp[101][10001];

    bool helper(int i , int  j ,string s , string t)
    {
        if( i == s.length())  // we reached at end of s
            return true;

        if( j == t.length())
            return false;

        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == t[j])
           return dp[i][j]  = helper(i+1,j+1,s,t);
        else
            return dp[i][j]  = helper(i,j+1,s,t);
        
    }
    bool isSubsequence(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return helper(0,0,s,t);
        
    }
};