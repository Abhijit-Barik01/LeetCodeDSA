class Solution {
public:
    string minWindow(string s, string t) {

        int sLen = s.size();
        int requiredCount  = t.size();
        if(t.length() > sLen)
            return "";

        int i=0,j=0;
        int start_i =0;
        unordered_map<char,int>mp;
        int Window_Size = INT_MAX;

        for(auto &c:t)
            mp[c]++;


        while( j < sLen)
        {
            char ch =s[j];
            if(mp[ch] > 0)
            {
                requiredCount--;
            }
            mp[ch] -- ;
             while(requiredCount == 0)
             {
                int curr_window = j-i+1;

                if(curr_window < Window_Size)
                {
                    Window_Size =curr_window;
                    start_i = i;
                }
                mp[s[i]]++;
                if(mp[s[i]] > 0)
                    requiredCount ++;
                
                i++;
             }
            j++;
        }

    return Window_Size == INT_MAX ? "" : s.substr(start_i,Window_Size);
    }
};