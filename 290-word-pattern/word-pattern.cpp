class Solution {
public:
    bool wordPattern(string pattern, string s) {

        vector<string>words ;
        string word;

        for(int i =0 ; i<= s.length();i++)
        {
            if(s[i] == ' ' || i== s.length())
            {
                if(!word.empty())
                {
                    words.push_back(word);
                    word.clear();
                }
               
            }else
            {
                word+=s[i];
            }
        }

        if(pattern.length() != words.size())
            return false;
        
        unordered_map<string,char>StringToChar;
        unordered_map<char,string>CharToString;

        for(int i =0 ; i< pattern.size();i++)
        {
            char c = pattern[i];
            string w = words[i];

            if(StringToChar.count(w))
            {
                if(StringToChar[w] !=c) return false;
            }
            else
            {
                if(CharToString.count(c))
                    return false;
                StringToChar[w] = c;
                CharToString[c] = w;
            }
        }
         return true;
        
    }
};