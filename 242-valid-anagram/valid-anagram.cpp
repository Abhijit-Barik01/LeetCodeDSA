class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1= s.length();
        int n2 =t.length();

        if(n1 != n2)
            return false;

        int freq[256];

        for(int i =0; i<n1;i++)
        {
            freq[s[i]]++;
            freq[t[i]]--;
        }

        for(int i=0;i<256;i++){
           if(freq[i]!=0)return false;
    }
       return true; 
    }
};