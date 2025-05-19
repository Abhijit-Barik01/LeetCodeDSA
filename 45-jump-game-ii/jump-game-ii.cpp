class Solution {
public:
    vector<int> dp;
    
    int solve(vector<int>& nums, int idx) {
        if (idx >= (int)nums.size() - 1) {
            return 0;  // Reached or passed the last index, no more jumps needed
        }
        if (dp[idx] != -1) 
            return dp[idx];
        
        int minJump = INT_MAX;
        int maxJump = nums[idx];
        for (int i = 1; i <= maxJump; i++) {
            int nextIdx = idx + i;
            if (nextIdx < (int)nums.size()) {
                int jumps = solve(nums, nextIdx);
                if (jumps != INT_MAX) {  // Only consider valid paths
                    minJump = min(minJump, jumps + 1);
                }
            }
        }
        
        return dp[idx] = minJump;
    }
    
    int jump(vector<int>& nums) {
        dp.assign(nums.size(), -1);  // resize dp to nums size and initialize with -1
        return solve(nums, 0);
    }
};
