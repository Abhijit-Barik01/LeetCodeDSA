class Solution {
public:
    int maxScore(string s) {
        int ans  =0;
        int ones = count(s.begin(),s.end(),'1');
        int zero =0;
        for(int i =0 ; i < s.size()-1 ;i++)
        {
            if(s[i]=='0')
            {
                zero =zero+1;
            }

            if(s[i]=='1')
            {
                ones =ones-1;
            }

           
            
            ans = max(ans, zero+ones);
        }
        return ans;
    }
};
