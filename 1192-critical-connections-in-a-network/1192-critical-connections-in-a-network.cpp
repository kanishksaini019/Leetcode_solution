class Solution {
public:
void dfs(int node,int parent,vector<vector<int>>& adj,vector<int>& vis,vector<vector<int>>& bridge,vector<int>& tim,vector<int>& low,int &timer)
{
vis[node]=1;
tim[node]=timer;
low[node]=timer;
timer++;
for(auto it:adj[node])
{
    if(it==parent)
    continue;
    if(vis[it]==0)
    {
 dfs(it,node,adj,vis,bridge,tim,low,timer);
 low[node]=min(low[node],low[it]);
 if(low[it]>tim[node])
 bridge.push_back({it,node});
    }
    else
    {
        low[node]=min(low[node],tim[it]); 
    }
}

}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
     vector<vector<int>>adj(n);
     for(auto it:connections)
     {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
     }  
     vector<vector<int>>bridge;
     vector<int>vis(n,0);
     vector<int>low(n);
     vector<int>tim(n);
     int timer=1;
   
            dfs(0,-1,adj,vis,bridge,tim,low,timer);
      
     return bridge;
    }
};