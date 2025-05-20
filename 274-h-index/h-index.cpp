class Solution {
public:
    int hIndex(vector<int>& citations) {
        int maxHindex = INT_MIN;
        int n =citations.size();
        for(int  i = 0 ; i <=n ; i++ )
        {  int count =0;
            for(int j =0 ; j <n ; j++ )
            {
                if(i <= citations[j])
                {
                    count++;
                }
                
            }
            if(count >= i)
            {
                maxHindex = max(maxHindex,i);
            }
            
            
        }
        return maxHindex;
    }
};