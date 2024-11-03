class Solution {
public:
    bool rotateString(string s, string goal) {
        if( s.length() != goal.length()) 
            return false;
        string s1=s+s;

        return s1.find(goal) < s1.length();
    }
};