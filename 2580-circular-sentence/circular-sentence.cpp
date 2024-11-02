class Solution {
public:
    bool isCircularSentence(string sentence) {
        char first=sentence[0];
        int n=sentence.size();
        char last = sentence[n-1];

        if(last != first)
        {
            return false;
        }


        for(int i =1 ; i < sentence.size()-1 ; i++)
        {
             if(sentence[i] == ' ')
             {
                first = sentence[i-1];
                last = sentence[i+1];

             }
            if(last != first)
            {
                return false;
            }
        }
        return true;
    }
};