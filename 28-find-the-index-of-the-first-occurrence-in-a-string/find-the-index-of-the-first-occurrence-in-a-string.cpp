class Solution {
public:
    int strStr(string haystack, string needle) {

        int n = haystack.size();
        int m = needle.size();

        for(int winStart = 0 ; winStart <=n-m ; winStart++)
        {
            for(int i =0 ; i< m; i++)
            {
                if(needle[i] != haystack[i+winStart])
                    break;
            

            if(i == m-1)
                return winStart;

        }
    }
       return -1;
    }
};