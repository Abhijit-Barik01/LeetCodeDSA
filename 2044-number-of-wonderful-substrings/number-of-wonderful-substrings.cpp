class Solution {
public:
typedef long long ll;
    long long wonderfulSubstrings(string word) {
        unordered_map<int,int>mp;
        mp[0] =1;
        ll currXor = 0;
        ll result =0 ;

        for(auto chr1 : word)
        {
            ll shift =  chr1 -'a';
            currXor = currXor^(1 << shift);
            result +=mp[currXor];
            for(char chr ='a';chr <='j';chr++)
            {   shift = chr -'a';
                ll oddXor = currXor^(1 << shift);
                result +=mp[oddXor];
            }

            mp[currXor]++;
        }
        
        return result;
    }
};