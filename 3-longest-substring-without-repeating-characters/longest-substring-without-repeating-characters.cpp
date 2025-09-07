class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        string temp; 
        temp+= s[0];
        int n = s.size();
        if (n==0) return 0;

        int i =1;
        int ans = 1;
        


        while(i < n)
        {
            size_t pos = temp.find(s[i]);
            if(pos != string::npos)
            {
               ans = max(ans, (int)temp.length());
               temp= temp.substr(pos+1)+s[i];

            }
            else
            {
                temp+=s[i];
            }
            i++;

        }
        ans = max(ans, (int)temp.length());
        return ans;
    }
};