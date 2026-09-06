class Solution {
public:
void bfs(int& i,int& j,vector<vector<char>>& grid,vector<vector<int>>& vis)
{
    int n=grid.size();
    int m=grid[0].size();
    queue<pair<int,int>>q;
    q.push({i,j});
   vis[i][j]=1;
    while(!q.empty())
    {
        int col=q.front().second;
        int row=q.front().first;
q.pop();
for(int delrow=1;delrow>=-1;delrow--)
{
    for(int delcol=1;delcol>=-1;delcol--)
    {
      if(abs(delrow)==abs(delcol))
      continue;
     
        int coll=col+delcol;
        int roww=row+delrow;
        if(coll>=0&&coll<m&&roww>=0&&roww<n&&grid[roww][coll]=='1'&&!vis[roww][coll]){
        vis[roww][coll]=1;
        q.push({roww,coll});
        }
    }
}
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
vector<vector<int>>vis(n,vector<int>(m,0));
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
if(!vis[i][j]&&grid[i][j]=='1')
{
    cnt++;
    bfs(i,j,grid,vis);
}
    }
}
return cnt;
    }
};