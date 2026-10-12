class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j= i+1;j<n;j++)
            {
                int wt=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj[i].push_back({j,wt});
                adj[j].push_back({i,wt});
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        vector<int>vis(n,0);
     
        int sum=0;
        while(!pq.empty())
        {
            int node=pq.top().second;
            int wt=pq.top().first;
            if(vis[node]==1)
            {pq.pop();
            continue;
            }
            sum+=wt;
            vis[node]=1;
            pq.pop();
            for(auto it:adj[node])
            {
                if(vis[it.first]==0)
                {
                    pq.push({it.second,it.first});
                }
            }
        }
        return sum;
    }
};