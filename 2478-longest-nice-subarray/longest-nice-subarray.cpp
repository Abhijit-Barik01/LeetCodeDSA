class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int result = 1;
        int i = 0;
        int j = 0;
        int n = nums.size();
        int mask = 0;

        while( j < n)
        {
                while(( mask & nums[j])!= 0)
                {
                    mask =(mask^nums[i]);
                    i++;
                }
                
                mask = (mask | nums[j]);
                result = max(result, j-i+1);
                j++;
        }
        return result;
    }
};