class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int>mp;

        for(auto &x: nums)
        {
            mp[x]++;
        }
        
        int n = nums.size();

         for(auto &ele:mp)
        {
            if(ele.second == n/2)
                return ele.first;
        }
        return -1;
    }
};