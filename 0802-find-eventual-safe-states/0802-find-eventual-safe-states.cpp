class Solution {
public:
bool dfs(vector<vector<int>>& graph,vector<int>& check,vector<int>& vis,vector<int>& currpath,int currnode)
{
    currpath[currnode]=1;
    vis[currnode]=1;
    check[currnode]=0;
    for(auto it:graph[currnode])
    {
        if(!vis[it])
        {
           if(dfs(graph,check,vis,currpath,it)==true)
           {
            return true;
           }
        }
        else
        {
            if(currpath[it]==1){
                check[it]=0;
            return true;
            }
        }
    }
    check[currnode]=1;
    currpath[currnode]=0;
    return false;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
      vector<int>check(n,0);
        vector<int>vis(n,0);
        vector<int>currpath(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(graph,check,vis,currpath,i);
            }
        }vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(check[i]==1)
            ans.push_back(i);
        }
        return ans;
    }
};