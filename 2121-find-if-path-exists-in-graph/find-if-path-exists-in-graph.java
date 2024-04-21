class Solution {
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        Map<Integer,List<Integer>>graph = new HashMap<>();
        for(int []edge:edges)
        {
            int u =edge[0];
            int v = edge[1];
            graph.computeIfAbsent(u, val->new ArrayList<>()).add(v);
            graph.computeIfAbsent(v,val -> new ArrayList<>()).add(u);

        }
            
            Queue<Integer>queue = new LinkedList<>();
            boolean [] seen = new boolean[n];
            seen[source] =true;

            queue.offer(source);

            while(!queue.isEmpty())
            {
                int currNode = queue.poll();
                if(currNode == destination)
                {
                    return true;
                }

                for(int nextNode : graph.get(currNode))
                {
                    if(!seen[nextNode])
                    {
                        seen[nextNode] = true;
                        queue.offer(nextNode);
                    }
                }
            }
      return false;
        
    }
}