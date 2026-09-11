class Solution {
public:
void bfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int delrow[],int delcol[],int row,int col)
{
    queue<pair<int,int>>q;
    int n=grid.size();
    int m=grid[0].size();
    q.push({row,col});
    vis[row][col]=1;
   while(!q.empty())
   {
    int nrow=q.front().first;
    int ncol=q.front().second;
    q.pop();
    for(int k=0;k<4;k++)
    {
   int cr=delrow[k]+nrow;
   int cc=delcol[k]+ncol;
  if(cr>=0&&cr<n&&cc>=0&&cc<m)
  {
    if(!vis[cr][cc]&&grid[cr][cc]==1){
    vis[cr][cc]=1;
    q.push({cr,cc});
    }
  }
    }
   }
}
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<m;j++)
            {
                int row;
                if(i==0)
row=0;
else
row=n-1;
if(grid[row][j]==1&&!vis[row][j])
bfs(grid,vis,delrow,delcol,row,j);
            }
        }
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<n;j++)
            {
                int col;
                if(i==0)
                col=0;
                else
                col=m-1;
                if(!vis[j][col]&&grid[j][col]==1)
                bfs(grid,vis,delrow,delcol,j,col);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1&&!vis[i][j])
                ans++;
            }
        }
        return ans;
        

    }
};