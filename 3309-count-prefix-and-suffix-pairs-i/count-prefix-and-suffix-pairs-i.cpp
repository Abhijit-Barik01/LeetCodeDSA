class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for(int i =0; i < words.size()-1; i++)
        {
            for(int j = i+1;j < words.size();j++)
            {
                if(words[j].find(words[i])  == 0 && words[j].rfind(words[i]) ==
                 words[j].length() - words[i].length())
                 {
                    count ++;
                 }

            }
        }
         return count ;
        
    }
};