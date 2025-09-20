class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>MergeIntervals;
       
         sort(intervals.begin(),intervals.end());
          vector<int>TempIntervals=intervals[0];

         for(auto it : intervals)
         {
            if( TempIntervals[1] >= it[0])
            {
                TempIntervals[1] = max(TempIntervals[1],it[1]);
            }
            else{
                MergeIntervals.push_back(TempIntervals);
                TempIntervals=it;
            }
         }
       MergeIntervals.push_back(TempIntervals);

       return MergeIntervals;

    }
};