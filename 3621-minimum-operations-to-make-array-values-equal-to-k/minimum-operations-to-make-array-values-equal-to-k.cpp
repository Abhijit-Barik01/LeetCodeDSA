class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> s1;
        for( auto &x: nums)
        {
            if (k > x)
                return -1;
            else
            {
                if( x > k)
                {
                    s1.insert(x);
                }

            }
        }
        return s1.size();
        
    }
};