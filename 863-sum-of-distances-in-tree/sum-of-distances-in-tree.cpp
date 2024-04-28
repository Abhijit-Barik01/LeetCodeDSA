class Solution {
public:
long root_result;
vector<int> count;
int N;

     int dfsroot(unordered_map<int,vector<int>>&adj,int currNode, int prevNode, int currrentDorrie)
     {
          int total_countofNodes = 1;
        root_result += currrentDorrie;
      

        for(int &child : adj[currNode])
        {
          if(prevNode == child)
          {
            continue;   
          }
          total_countofNodes += dfsroot(adj,child,currNode,currrentDorrie+1);
        }

        count[currNode] = total_countofNodes;

        return total_countofNodes;

     }

     void DFSresult( unordered_map<int,vector<int>>&adj,int currNode, int prevNode, vector<int>&result)
     {
                 for(int &child : adj[currNode])
                 {
                    if(prevNode == child)
                    {
                        continue;
                    }
                    result[child] = result[currNode]- count[child] + (N - count[child]);
                    DFSresult(adj,child,currNode,result);


                 }
     }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        unordered_map<int,vector<int>>adj;
        for (auto &edge: edges)
        {
        int u = edge[0];
        int v = edge[1];
        adj[v].push_back(u);
        adj[u].push_back(v);
        }
     
        count.resize(N,0);
        root_result = 0;

       dfsroot(adj,0,-1,0);
       vector<int>result(N,0);
       result[0] = root_result;

       DFSresult(adj,0,-1,result);
       return result;

    }
};