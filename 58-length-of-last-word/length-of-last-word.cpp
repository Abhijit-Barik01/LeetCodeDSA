class Solution {
public:
    int lengthOfLastWord(string s) {
        int n =s.size(), length =0;
        while(n > 0)
        {
            n--;
            if(s[n] !=' ')
            {
                length++;
            }
            else if(length > 0)
            {
                return length;
            }
        }
        
        return length;
    }
};