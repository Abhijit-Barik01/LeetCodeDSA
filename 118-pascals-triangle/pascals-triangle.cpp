class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>>nums;

        for(int i =0; i <numRows;i++ )
        {
             vector<int>temp(i+1);

             for(int j =0 ;j <=i;j++)
             {
                if(j ==0 || i==j)
                {
                    temp[j]=1;
                }
                else
                {
                    temp[j] = nums[i-1][j-1]+nums[i-1][j];
                }
             }
             nums.push_back(temp);
        }
        return nums;
        
    }
};