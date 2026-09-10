class Solution {
public:
void dfs(vector<vector<char>>& board,vector<vector<int>>& vis,int i,int j,int delrow[],int delcol[])
{
queue<pair<int,int>>q;
q.push({i,j});
vis[i][j]=1;
int n=board.size();
int m=board[0].size();
while(!q.empty())
{
    int r=q.front().first;
    int c=q.front().second;
    q.pop();
    for(int k=0;k<4;k++)
    {
        int cr=delrow[k]+r;
        int cc=delcol[k]+c;
        if(cr>=0&&cr<n&&cc>=0&&cc<m)
        {
            if(!vis[cr][cc]&&board[cr][cc]=='O')
            {
                vis[cr][cc]=1;
                q.push({cr,cc});
            }
        }
    }  
}
}
    void solve(vector<vector<char>>& board) {
        
        int n=board.size();
        int m=board[0].size();
         vector<vector<int>>vis(n,vector<int>(m,0));
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
            if(board[row][j]=='O'&&!vis[row][j])
            dfs(board,vis,row,j,delrow,delcol);
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
if(board[j][col]=='O'&&!vis[j][col])
dfs(board,vis,j,col,delrow,delcol);
        }
       }
       for(int i=0;i<n;i++)
       {
        for(int j=0;j<m;j++)
        {
            if(vis[i][j]!=1&&board[i][j]=='O')
            {
                board[i][j]='X';
            } 
        }
       }
       
    }
};