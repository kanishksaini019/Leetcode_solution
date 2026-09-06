class Solution {
public:
void dfs(vector<vector<int>>& adjls,int i,vector<int>& vs)
{
    vs[i]=1;
for(auto it:adjls[i])
{
  if(!vs[it])
  {
    dfs(adjls,it,vs);
  }
}
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
       vector< vector<int>> adjls(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
               if(isConnected[i][j]==1&&i!=j)
               {
                adjls[i].push_back(j);
               }
            }
        }
        vector<int>vs(n,0);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
    if(!vs[i])
    {
        cnt++;
        dfs(adjls,i,vs);
    }
        }

        return cnt;
    }
};