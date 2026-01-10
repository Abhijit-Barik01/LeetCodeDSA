class Solution {
public:
    int n,m;
    int dp[1001][1001];

    int Solve(string &s1,string &s2,int i,int j)
    {
        if(i >= n && j >=m)
            return 0;

        if(dp[i][j] !=-1)
            return dp[i][j];

        if(i>=n)
            return s2[j]+Solve(s1,s2,i,j+1);
        else if( j>=m)
            return s1[i]+Solve(s1,s2,i+1,j);
        
        if(s1[i] == s2[j])
            return Solve(s1,s2,i+1,j+1);

        //Two possible

        int delete_s1= s1[i]+Solve(s1,s2,i+1,j);
        int delete_s2 = s2[j]+Solve(s1,s2,i,j+1);

        return dp[i][j]=min(delete_s1,delete_s2);
        
    }

    int minimumDeleteSum(string s1, string s2) {
        n = s1.size();
        m =s2.size();
        memset(dp,-1,sizeof(dp));
        return Solve(s1,s2,0,0);

    }
};