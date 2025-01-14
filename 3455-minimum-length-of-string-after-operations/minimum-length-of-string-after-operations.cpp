class Solution {
public:
    int minimumLength(string s) {
        vector<int>frequency(26,0);
        int totalLength =0;

        for(int i = 0; i<s.length(); i++)
        {
            frequency[s[i] -'a'] ++;
        }

        for(int fre: frequency )
        {   if (fre == 0) continue;
            if(fre%2 == 0)
            {
              totalLength +=2;
            }
            else
            {
             totalLength+=1;
            }
        }
        return totalLength;
    }
};