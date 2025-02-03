class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int count  =1;
        int result = 0;

        for(int i =0;i<nums.size()-1; i++)
        {
             if(nums[i] < nums[i+1])
             {
                count ++;
             }
             else{
                result = max(result,count);
                count =1;
             }
        }
        result = max(result,count);
        count =1;
        for(int i =0;i<nums.size()-1; i++)
        {
             if(nums[i] > nums[i+1])
             {
                count ++;
             }
             else{
                result = max(result,count);
                count =1;
             }
        }
        result = max(result,count);
        return result;
    }
};