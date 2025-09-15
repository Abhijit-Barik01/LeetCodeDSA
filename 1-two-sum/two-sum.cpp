class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int>mp;
        for(int i=0;i < nums.size();i++)
        {    int otherele = target - nums[i];

            if(mp.find(otherele) != mp.end())
            {
                return {mp[otherele],i};
            }
            mp[nums[i]] =i;

        }
        return {};
    }
};