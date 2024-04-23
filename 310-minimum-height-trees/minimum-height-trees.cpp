class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
            return {0};
       vector<int>result;
       unordered_map<int,vector<int>>adj;
       unordered_map<int,int>indegree;

       for(auto edge: edges)
       {
         int  u = edge[0];
         int  v = edge[1];
         adj[u].push_back(v);
         adj[v].push_back(u);
         indegree[u]++;
         indegree[v]++;
       }

       queue<int>q;
       for(int i=0; i<n ;i++)
       {
          if(indegree[i] == 1)
          {
            q.push(i);
          }
       }

       while(n > 2 )
       {
         
          int qsize = q.size();

            while(qsize --)
            {
                int ele = q.front();
                q.pop();
                n =n -1;

                for(auto neighbor:adj[ele] )
                {
                    indegree[neighbor] --;
                    if(indegree[neighbor] ==1)
                    {
                        q.push(neighbor);
                    }
                }
            }
       }
       
       while(!q.empty())
       {
         result.push_back(q.front());
         q.pop();
       }
        return result;        
    }
};