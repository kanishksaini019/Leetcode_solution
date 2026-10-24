class disjointset
{
    vector<int>size;
    vector<int>parent;
    public:
    disjointset(int n)
    {
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }
    public:
   int finduparent(int node)
    {
        if(parent[node]==node)
        return node;
        else
        return parent[node]=finduparent(parent[node]);
    }
    void unionbysize(int u,int v)
    {
        int uu=finduparent(u);
        int uv=finduparent(v);
        if(uu==uv)
        return;
        if(size[uu]>size[uv])
        {
            parent[uv]=uu;
            size[uu]+=size[uv];
        }
        else if(size[uu]<size[uv])
        {
            parent[uu]=uv;
            size[uv]+=size[uu];
        }
        else
        {
            parent[uu]=uv;
            size[uv]+=size[uu];
        }
    }
    public:
    int getsize(int node)
{
    return size[finduparent(node)];
}
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
      int n=grid.size();
      disjointset ds(n*n);
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]==0)
            {
                continue;
            }
            int drow[]={-1,0,1,0};
            int dcol[]={0,1,0,-1};
            for(int k=0;k<4;k++)
            {
                int nrow=i+drow[k];
                int ncol=j+dcol[k];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<n)
                {
                    if(grid[nrow][ncol]==1)
                    ds.unionbysize(i*n+j,nrow*n+ncol);
                }
            }
        }
      }  
      int cnt=0;
for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        if(grid[i][j]==0)
        cnt++;
    }
}
if(cnt==0)
return n*n;
      int ans=0;
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]==1)
            {
                continue;
            }
            set<int>st;
            int drow[]={-1,0,1,0};
            int dcol[]={0,1,0,-1};
            for(int k=0;k<4;k++)
            {
                int nrow=i+drow[k];
                int ncol=j+dcol[k];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<n)
                {
                    if(grid[nrow][ncol]==1)
                    st.insert(ds.finduparent(nrow*n+ncol));
                }
            }
            int size=1;
            for(auto it:st)
            {
size+=ds.getsize(it);
            }
ans=max(ans,size);
        }
      }
      return ans; 
    }
};