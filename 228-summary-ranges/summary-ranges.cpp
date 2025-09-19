class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>result;
        if(nums.empty())
            return result;

        for(int i =0 ; i< nums.size();i++)
        {
            int start = nums[i];
            int j =i;

            while(j+1 < nums.size() && nums[j]+1 == nums[j+1] ){
                j++;
            }
            if(start == nums[j])
                result.push_back(to_string(start));
            else
                result.push_back(to_string(start) +"->"+ to_string(nums[j]));

            i = j;
        }
       return  result;
    }
};