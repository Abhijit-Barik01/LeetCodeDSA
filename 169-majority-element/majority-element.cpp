class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count =1;

        int res =0;


        for(int i=1; i< nums.size();i++)
        {
            if(nums[i]==  nums[res])
            {
                count ++;
            }
            else
            {
                count --;
            }

            if(count == 0)
            {
                count=1;
                res = i;
            }
        }

       count  = 0;
        for(int i =0 ; i < nums.size(); i++)
        {
            if(nums[i] == nums[res])
            {
                count ++;
            }
        }

        int n= nums.size()/2;
        if( count < n )
            return -1;
        return nums[res] ;
    }
};