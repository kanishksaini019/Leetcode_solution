class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2&&vis[i][j]!=2)
                {
                vis[i][j]=2;
                q.push({{i,j},0});
                }
            }
        }
        int tm=0;
        while(!q.empty())
        {
         int row=q.front().first.first;
         int col=q.front().first.second;
         int time=q.front().second;
         q.pop();
tm=max(tm,time);
for(int delrow=-1;delrow<=1;delrow++)
{
    for(int delcol=-1;delcol<=1;delcol++)
    {
     if(abs(delcol)==abs(delrow))
     continue;
     int cr=row+delrow;
     int cc=col+delcol;
     if(cr>=0&&cr<n&&cc>=0&&cc<m&&vis[cr][cc]!=2&&grid[cr][cc]==1)
     {
        vis[cr][cc]=2;
     q.push({{cr,cc},time+1});
     } 
    }
}
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]!=2&&grid[i][j]==1)
                return -1;
            }
        }
        return tm;
    }
};