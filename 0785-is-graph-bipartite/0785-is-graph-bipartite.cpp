class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
      int n=graph.size();
      vector<int>vis(n,-1);
      queue<int>q;
  for(int i=0;i<n;i++)
  {
    if(vis[i]==-1)
    {
        q.push(i);
        vis[i]=0;
    }
    while(!q.empty())
{
    int node=q.front();
    int colour=vis[node];
    q.pop();
    for(auto it:graph[node])
    {
       if(vis[it]==-1)
       {
        vis[it]=!colour;
        q.push(it);
       }
       else
       {
        if(vis[it]==colour)
        return false;
       }
    }
}
  }
return true;
    }
};