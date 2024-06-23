class Solution {
public:
    int n;
    int dp[1001][1001];
    bool isPred(string &str1, string &str2)
    {
        int N= str1.length();
        int M = str2.length();
        if(M>=N || N-M !=1 )
            return false;
        int i=0;
        int j =0;

        while(i <  N && j < M)
        {
            if(str1[i]==str2[j])
                j++;
            i++;
        }
        return j==M;
    }
    
     static bool myFuction(string &word1, string &word2)
     {
            return word1.length()< word2.length();
     }
     int lis(vector<string>& words,int curr, int prev)
     {
        if(curr == n)
            return 0;
        if( prev != -1 && dp[curr][prev] !=-1)
            return dp[curr][prev];
        int taken=0,nontaken=0;
        if(prev == -1 || isPred(words[curr],words[prev]))
        {
            taken = 1+lis(words,curr+1,curr);
        }
        nontaken =lis(words,curr+1,prev);
        if(prev != -1)
        {
            dp[curr][prev]= max(taken,nontaken);
        }

        return max(taken,nontaken);
     }
    int longestStrChain(vector<string>& words) {
        memset(dp,-1,sizeof(dp));
        n = words.size();
        sort(words.begin(),words.end(),myFuction);
        

        return lis(words,0,-1);

    }
};