class Solution {
public:
bool bfs(vector<vector<int>>& vis,vector<vector<char>>& grid,int sr,int sc,int delcol[],int delrow[])
{
    int n=grid.size();
    int m=grid[0].size();
queue<pair<pair<int,int>,pair<int,int>>>q;
q.push({{sr,sc},{-1,-1}});
vis[sr][sc]=1;
while(!q.empty())
{
    int row=q.front().first.first;
    int col=q.front().first.second;
    int prow=q.front().second.first;
    int pcol=q.front().second.second;
    q.pop();
    for(int k=0;k<4;k++)
    {
        int nrow=delrow[k]+row;
        int ncol=delcol[k]+col;
        if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m)
        {
          if(grid[row][col]!=grid[nrow][ncol])
          continue;
          if(!vis[nrow][ncol]){
          vis[nrow][ncol]=1;
q.push({{nrow,ncol},{row,col}});
          }
          else
          {
            if(nrow==prow&&ncol==pcol)
            continue;
            else 
            return true;
          }
        }
    }
}
return false;
}

    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
   vector<vector<int>>vis(n,vector<int>(m,0));
      int delrow[]={-1,0,1,0};
      int delcol[]={0,1,0,-1};
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j])
            {
                if(bfs(vis,grid,i,j,delcol,delrow))
                return true;
            }
        }
      }
      return false;
    }
};