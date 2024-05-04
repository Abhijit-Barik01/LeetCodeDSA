class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int count =0;
        int low=0;
        int high=people.size()-1;
        sort(people.begin(),people.end());
        while(low <= high)
        {
            if(people[low]+people[high]<=limit)
            {
                count++;
                low=low+1;
                high=high-1;
            }
            else{
                count++;
                high=high-1;

            }
        }
        return count;
    }
};