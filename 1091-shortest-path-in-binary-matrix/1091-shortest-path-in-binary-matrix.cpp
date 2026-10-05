class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      int n=grid.size();
      int m=grid[0].size();
      if(grid[0][0]==1)
      return -1;
      queue<pair<int,pair<int,int>>>q;  
      vector<vector<int>>dis(n,vector<int>(m,1e9));
      q.push({1,{0,0}});
      dis[0][0]=1;
      while(!q.empty())
      {
        int r=q.front().second.first;
        int c=q.front().second.second;
        int dist=q.front().first;
        if(r==n-1&&c==n-1)
        {
            return dist;
        }
        q.pop();
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
            int nr=i+r;
            int nc=j+c;
            if(nr>=0&&nr<n&&nc>=0&&nc<n)
            {
                if(dist+1<dis[nr][nc]&&grid[nr][nc]==0)
                {
                    dis[nr][nc]=dist+1;
                    q.push({dist+1,{nr,nc}});
                }
            }
            }
        } 
      }
      return -1;

    }
};