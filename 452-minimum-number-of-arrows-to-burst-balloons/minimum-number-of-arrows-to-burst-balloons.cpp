class Solution {
public:
  static   bool comp(vector<int>& a,vector<int>& b)
  {
      return(a[1]<b[1]);
  }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),comp);
        int prev=0;
        int res=1;
        int n=points.size();
        
        for(int curr=1;curr<n;curr++)
        {
            if(points[curr][0]>points[prev][1])
            {
                res++;
                prev=curr;
            }
        }
        return res;
    }
};