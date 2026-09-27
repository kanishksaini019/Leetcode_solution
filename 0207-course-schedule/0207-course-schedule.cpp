class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>>adj(numCourses);
   
     vector<int>indegree(numCourses,0);
    for(auto it:prerequisites)
    {
        int u=it[1];
        int v=it[0];
        adj[u].push_back(v);
        indegree[v]++;
    }
    queue<int>q;
    int n=indegree.size();
    for(int i=0;i<n;i++)
    {
if(indegree[i]==0)
q.push(i);   
 }
 vector<int>topo;
 while(!q.empty())
 {
    int node=q.front();
    q.pop();
    topo.push_back(node);
    for(auto it:adj[node])
    {
        indegree[it]--;
        if(indegree[it]==0)
        {
            q.push(it);
        }
    }

 }
int n1=topo.size();
if(n1==n)
return true;
else
 return false;
    }
};