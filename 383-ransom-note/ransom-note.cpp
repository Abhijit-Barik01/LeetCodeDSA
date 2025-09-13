class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>mp;

        for(int i = 0; i < ransomNote.size();i++)
        {
            mp[ransomNote[i]]++;
        }

        for(int i = 0; i < magazine.size();i++)
        {
            if(mp.find(magazine[i]) != mp.end())
                mp[magazine[i]]--;
        }

        for(auto &pair : mp)
        {
            if(pair.second > 0)
                return false;
            
        }
        return true;
        
    }
};