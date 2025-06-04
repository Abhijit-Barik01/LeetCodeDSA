class Solution {
public:
    string answerString(string word, int numFriends) {
        int n= word.size();
        if(numFriends == 1)
            return word;
        
        int longeststr = n - (numFriends -1); // give eyeone a single charecter.
        string result = "";
        for(int i =0; i<n; i++)
        {
            int possiblestr=  min(longeststr,n-i);

            result = max(result,word.substr(i,possiblestr));

        }
        return result;
    }
};