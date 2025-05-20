class Solution {
public:
    int hIndex(vector<int>& citations) {
        int maxHindex = INT_MIN;  //design by me
        int n =citations.size();
        for(int  index = 0 ; index <=n ; index++ )
        {  int count =0;
            for(int j =0 ; j <n ; j++ )
            {
                if(index <= citations[j])
                {
                    count++;
                }
                
            }
            if(count >= index)
            {
                maxHindex = max(maxHindex,index);
            }
            
            
        }
        return maxHindex;
    }
};