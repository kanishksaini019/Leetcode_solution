class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:roads)
    {
        adj[it[0]].push_back({it[1],it[2]});
          adj[it[1]].push_back({it[0],it[2]});
    }
    int mod=int(1e9+7);
    priority_queue<pair<long long,long long >,vector<pair<long long ,long long>>,greater<pair<long long ,long long>>>pq;
    vector<long long>dist(n,LLONG_MAX);
    vector<int>ways(n,0);
    ways[0]=1;
    dist[0]=0;
    pq.push({0,0});
    while(!pq.empty())
    {
        int node=pq.top().second;
        long long  distance=pq.top().first;
        pq.pop();
        for(auto it:adj[node])
        {
            int nei=it.first;
            long long  edgwt=it.second;
            if(edgwt+distance<dist[nei])
            {
               dist[nei]=edgwt+distance;
               ways[nei]=ways[node]; 
               pq.push({dist[nei],nei});
            }
            else if(edgwt+distance==dist[nei])
            {
                ways[nei]=(ways[nei]+ways[node])%mod;
            }
        }
      
    }  return ways[n-1]%mod;
    }
};