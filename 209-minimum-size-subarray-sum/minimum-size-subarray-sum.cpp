class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int maxL = INT_MAX;
        int n = nums.size();
        int j=0;
        for(int i=0;i <n;i++)
        {
            sum += nums[i];
            while(sum >= target)
            {
                maxL= min(maxL,(i-j+1));
                sum-= nums[j];
                j++;
            }
        }
        return maxL == INT_MAX?0:maxL;
    }
};