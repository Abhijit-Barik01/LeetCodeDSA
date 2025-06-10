class Solution {
public:
    int maxDifference(string s) {

        unordered_map<char,int>mp;

        for(auto ch: s)
        {
            mp[ch]++;
        }
       int maxodd = 1, minEven = s.size();

       for(const auto& [_,value] :mp)
       {
            if(value%2 ==1)
                maxodd=max(maxodd,value);
            else
                 minEven=min(minEven,value);
       }

       return maxodd - minEven;
        
    }
};