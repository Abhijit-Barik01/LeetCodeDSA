class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int T_time =0;
        int x1,x2,y1,y2;
        for(int i =0; i< points.size()-1;i++)
        {
           
                 x1= points[i][0];
                 y1= points[i][1];
                 x2= points[i+1][0];
                 y2= points[i+1][1];
                 T_time+=max(abs(x1-x2),abs(y1-y2));
           
        }
        return T_time;
    }
    
};