class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});//stops,node,dist
        vector<int>dist(n,1e9);
        dist[src]=0;
        while(!q.empty())
        {
int node=q.front().second.first;
int distance=q.front().second.second;
int stops=q.front().first;
q.pop();
if(stops>k+1)
continue;
for(auto it:adj[node])
{
    int dista=it.second;
    int neig=it.first;
    if(dista+distance<dist[neig]&&stops+1<=k+1)
    {
        dist[neig]=dista+distance;
        q.push({stops+1,{neig,dist[neig]}});
    }
}
        }
        if(dist[dst]==1e9)
        return -1;
        else
        return dist[dst];
    }
};