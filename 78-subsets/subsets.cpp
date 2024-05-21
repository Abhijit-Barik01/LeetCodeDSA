class Solution {
private:
void solve(vector<int>nums,vector<int>output,vector<vector<int>>&ans, int index)
{
    //base case
  
    if(index >= nums.size())
    {
        ans.push_back(output);
        return;
    }
    solve(nums,output,ans,index+1);
    int ele=nums[index];
    output.push_back(ele);
    solve(nums,output,ans,index+1);
   // output.pop_back();
}
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int index=0;
        vector<int>output;
        solve(nums,output,ans,0);
        return ans;
        
    }
};