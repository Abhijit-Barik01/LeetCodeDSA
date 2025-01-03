class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char>s{'a','e','i','o','u'};
        vector<int>prefix(words.size());
         vector<int>ans(queries.size());
         int sum = 0;

        for(int i =0; i < words.size(); i++)
        {
            string currentword = words[i];
            if(s.count(currentword[0])  &&  s.count(currentword[currentword.size()-1]) )
            {
                sum = sum+1;
            }
            prefix[i]= sum;

       }

        for(int j =0; j < queries.size(); j++)
        {   vector<int>currQ = queries[j];
            ans[j] =prefix[currQ[1]] - (currQ[0] == 0 ? 0: prefix[currQ[0]-1]);
        }

        return ans;
        
    }
};