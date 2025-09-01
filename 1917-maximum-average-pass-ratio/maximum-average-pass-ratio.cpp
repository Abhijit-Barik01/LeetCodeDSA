class Solution {
public:
    #define P pair<double,int>
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<P>pr; //max_heap
        for(int i =0 ; i< classes.size();i++)
        {
           double cuur_pr = static_cast<double>(classes[i][0])/classes[i][1];
           double updated_pr = static_cast<double>(classes[i][0]+1)/(classes[i][1]+1);

           pr.push({(updated_pr -cuur_pr),i});


        }

        while(extraStudents--)
        {
            auto top_pr_index= pr.top().second;
            pr.pop();
            classes[top_pr_index][0]++;
            classes[top_pr_index][1]++;

               double cuur_pr = static_cast<double>(classes[top_pr_index][0])/classes[top_pr_index][1];
           double updated_pr = static_cast<double>(classes[top_pr_index][0]+1)/(classes[top_pr_index][1]+1);

           pr.push({(updated_pr - cuur_pr),top_pr_index});


        }
    double total_pr=0.0;

    for(int i =0 ; i< classes.size();i++)
    {
        total_pr +=static_cast<double>(classes[i][0])/classes[i][1];
    }
        
    return total_pr/classes.size();
        
    }
};