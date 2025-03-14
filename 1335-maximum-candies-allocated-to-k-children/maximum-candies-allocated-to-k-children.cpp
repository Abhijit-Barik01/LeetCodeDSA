class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {

        int maxCandies = 0;
        long total = 0;
        for(int  i =0 ; i <candies.size(); i++ )
        {   total += candies[i];
            maxCandies = max(maxCandies, candies[i]);
        }
        int low =1;
        int high =maxCandies;
        int result =0 ;
        if (total < k) {
            return 0;
        }

        while(low <= high)
        {
            int mid = low+(high - low)/2;

            if(canAllocate(candies,k,mid))
            {
                result = mid ;
                low = mid+1;
            }
            else
            {
                high = mid -1;
            }

        }
        return result;
    }
     bool canAllocate(vector<int>& candies, long long k,
                            int numOfCandies)
                            {
                                 long long int maxNumOfChildren = 0;

                                 for(int i =0; i < candies.size(); i++)
                                 {
                                    maxNumOfChildren += candies[i]/numOfCandies;
                                 }
                                 return maxNumOfChildren >= k;
                            }
};