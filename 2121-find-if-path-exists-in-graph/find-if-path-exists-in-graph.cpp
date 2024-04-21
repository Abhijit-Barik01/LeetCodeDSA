class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>graph;
        for(auto & edge:edges)
        {
            int a=edge[0];
            int b=edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);

        }
        vector<bool>seen(n);
        seen[source]=true;
        queue<int>bfs;
        bfs.push(source);
        while(!bfs.empty())
        {
            int currNode=bfs.front();
            seen[currNode]=true;
            bfs.pop();

            if(currNode == destination)
            {
                return true;
            }
            for(auto nextnode: graph[currNode])
            {
                if(!seen[nextnode])
                {
                    seen[nextnode]=true;
                    bfs.push(nextnode);
                }
            }
        }

return false;

    }
};