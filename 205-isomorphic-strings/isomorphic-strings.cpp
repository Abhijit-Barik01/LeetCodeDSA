class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int MapStoT[256]={0};
        int MapTtoS[256] ={0};

        for(int i =0; i < s.size();i++)
        {
            char c1 = s[i];
            char c2 =t[i];

            if(MapStoT[c1] == 0 && MapTtoS[c2] == 0 )
            {
                MapStoT[c1] = c2;
                MapTtoS[c2] = c1;

            }
            else if( !(MapStoT[c1] == c2  && MapTtoS[c2]== c1 ))
            {
                return false;
            }
        }
        return true;
    }
};