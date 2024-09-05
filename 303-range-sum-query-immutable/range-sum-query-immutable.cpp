class NumArray {
public:

  vector<int>resultsum;
    NumArray(vector<int>& nums) {
        resultsum.resize(nums.size());
        resultsum[0]=nums[0];
        for(int i=1; i< nums.size(); i++)
        {
            resultsum[i]= resultsum[i-1] + nums[i];
        }

      
        
    }
    
    int sumRange(int left, int right) {
        if(left == 0)
        {
            return resultsum[right];
        }
        return resultsum[right]- resultsum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */