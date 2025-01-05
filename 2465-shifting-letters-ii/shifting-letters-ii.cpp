class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n =s.size();
        vector<int>diff(n,0);
        //string result(n,' ');
        for(int i =0 ; i <shifts.size();i++)
        {
            
            int left = shifts[i][0];
            int right =shifts[i][1];

            if(shifts[i][2] == 0)
            {
                diff[left]--;
             
                if(right+1 < n)
                {
                        diff[right+1] ++;
                }
                

            }
            else
            {
                diff[left]++;
             
                if(right+1 < n)
                {
                        diff[right+1]--;
                }
            }
        }

        for(int i =1 ; i<n ;i++)
        {
            diff[i]= diff[i]+diff[i-1];
        }
        
        for(int  i = 0; i < n ; i++ )
        {
            int shift = diff[i] % 26;
            if(shift < 0 )
            {
                shift=shift+26;
            }
            s[i] = (s[i]- 'a' + shift)%26 +'a';
        }

        return s ;
    }
    
};