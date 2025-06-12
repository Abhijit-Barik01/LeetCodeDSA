class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxArr=0;
        for(int i =0 ; i < nums.size()-1;i++)
        {
            maxArr= max(maxArr,abs(nums[i]-nums[i+1] ));
        }
        maxArr =max(maxArr,abs(nums[0]-nums[nums.size()-1]));
        return maxArr;
    }
};