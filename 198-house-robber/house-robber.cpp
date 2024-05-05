class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n= nums.size();
        vector<int>result(n+1,0);

        result[0] =0;
        result[1]=nums[0];

        for(int i =2; i<=n;i++)
        {
            int steal = result[i-2]+nums[i-1];
            int skip =result[i-1];
            result[i]= max(steal,skip);
        }


        return result[n];
        
    }
};