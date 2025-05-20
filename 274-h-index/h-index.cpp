class Solution {
public:
    int hIndex(vector<int>& citations) {

        sort(citations.begin(),citations.end(),greater<int>());

        int i =0 , hmax =0 ;
        while( i < citations.size())
        {
            if(citations[i] >= i+1)
                hmax = i+1;
            else
                break;

            i++;

        }

       return hmax; 
    }
};