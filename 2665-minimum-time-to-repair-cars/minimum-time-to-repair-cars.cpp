class Solution {
public:
    typedef long long ll;
     bool checkAnswer(vector<int>& ranks, int cars , long long time)
     {  ll Ttime = 0;
        for( int i =0 ; i< ranks.size() ; i++)
        {
           Ttime += sqrt(time/ranks[i]);
        }
        return Ttime >= cars;
     }

    long long repairCars(vector<int>& ranks, int cars) {
        ll startTime = 1;
        int max_rank= *max_element(begin(ranks),end(ranks));
        ll highTime = 1ll*max_rank*cars*cars;
        ll resultTime = -1;
        while(startTime <=highTime )
        {
            ll mid =startTime + (highTime - startTime)/2;

            if(checkAnswer(ranks,cars,mid) == true)
            {
               resultTime = mid;
               highTime = mid-1;
            }
            else
            {
                startTime = mid+1;
            }
        }
       return resultTime;
    }
};