class Solution {
public:
void bfs(vector<vector<int>>& mat,vector<vector<int>>& vis,  queue<pair<pair<int,int>,int>>& q,vector<vector<int>>& dist,int delcol[],int delrow[])
{
    int n=mat.size();
    int m=mat[0].size();
    while(!q.empty())
    {
        int row=q.front().first.first;
        int col=q.front().first.second;
        int time=q.front().second;
        q.pop();
        for(int k=0;k<4;k++)
        {
            int nrow=delrow[k]+row;
            int ncol=delcol[k]+col;
            if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m)
            {
                if(vis[nrow][ncol]==1)
                {
                    vis[nrow][ncol]=0;
                    q.push({{nrow,ncol},time+1});
                    dist[nrow][ncol]=time+1;
                }
                else
              continue;
            }
        }
    }
}
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis=mat;
        vector<vector<int>>dist(n,vector<int>(m,-1));
   for(int i=0;i<n;i++)
   {
    for(int j=0;j<m;j++)
    {
        if(mat[i][j]==0){
        q.push({{i,j},0});
dist[i][j]=0;
        }
    }
   }
   bfs(mat,vis,q,dist,delcol,delrow);
   return dist;
    }
};