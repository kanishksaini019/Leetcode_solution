class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
     vector<vector<pair<int,int>>>adj(n+1);
     for(auto it:times)
     {
       adj[it[0]].push_back({it[1],it[2]});
     }
     vector<int>dist(n+1,1e9);
     dist[k]=0;
     int time=0;
     for(int i=0;i<n-1;i++)
     {
        for(auto it:times)
        {
            int u=it[0];
        int node=it[1];
        int edjwt=it[2];
        if(dist[u]!=1e9&&dist[u]+edjwt<dist[node])
        {
            dist[node]=dist[u]+edjwt;
        
        }
        }
     }
     for(int i=1;i<=n;i++)
     {
        if(dist[i]==1e9)
        return -1;
        time=max(time,dist[i]);
     }
     return time;   
    }
};