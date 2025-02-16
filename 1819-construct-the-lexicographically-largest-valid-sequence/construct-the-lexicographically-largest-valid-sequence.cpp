class Solution {
public:
    bool solve(int i,int n,vector<int>&result,vector<bool>&used )
    {

       if(i >= result.size())
            return true;
        if(result[i] != -1)
            return solve(i+1,n,result,used);
        
        for(auto num=n;num >= 1;num --)
        {
           if(used[num])
                continue;
            used[num] = true;
            result[i] =num;
            if(num == 1)
            { 
                if(solve(i+1,n,result,used))
                return true ; //move to next i
            }
            else
            {
                int next = result[i]+i;
                if(next < result.size() && result[next] == -1)
                {
                  result[next] = num;
                    if(solve(i+1,n,result,used))
                        return true ;
                    result[next] = -1; // undo if its return false 
                }
              

            }

            used[num] = false;
            result[i] =-1;
        }
         return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int>result(2*n-1, -1);
        vector<bool>used(n+1,false);

        solve(0,n,result,used);
        return result;
    }
};