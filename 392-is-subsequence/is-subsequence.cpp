class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length();
        int n= t.length();

        if( m==0 && n==0)
                return true;
        
        int i,j;
        for(i =0,j=0; j<n ; j++)
        {
                if(s[i] == t[j])
                {
                    i++;
                }
                 if(i==m)
                    return true;
        }
       
        return false;
        
    }
};