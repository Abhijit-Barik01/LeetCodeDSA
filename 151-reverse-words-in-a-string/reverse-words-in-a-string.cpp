class Solution {
public:
    string reverseWords(string s) {
        int i =0;
        int l=0,r=0;
        int n = s.length();

        reverse(s.begin(),s.end());

        while(i < n)
        {
            while(i < n && s[i] != ' ')

            {
                s[r++] =s[i++];
            }
            
            if(l < r)
            {
                s[r]= ' ';
                reverse(s.begin()+l,s.begin()+r);
                r++;
                l=r;
            }




            i++;
        }
        return s.substr(0,r-1);
    }
};