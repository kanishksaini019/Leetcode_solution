class Solution {
public:
class disjointset
{
    vector<int>parent;
    vector<int>rank;
    public:
    disjointset(int n)
    {
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
    }
  int uparent(int node)
  {
    if(node==parent[node])
    return node;
    else
    return parent[node]=uparent(parent[node]);
  }
  void unionbyrank(int u,int v)
{
    int uu=uparent(u);
    int uv=uparent(v);
    if(uparent(u)==uparent(v))
    return;
  if(rank[uu]>rank[uv])
  {
    parent[uv]=uu;
  }
  else if(rank[uu]<rank[uv])
  {
    parent[uu]=uv;
  }
  else
  {
    parent[uu]=uv;
    rank[uv]++;
  }
}   
};
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
map<string,int>mpp;
int n=accounts.size();
disjointset ds(n);

for(int i=0;i<n;i++)
{
    int n1=accounts[i].size();
for(int j=1;j<n1;j++)
{
    string s=accounts[i][j];
    if(mpp.find(s)==mpp.end())
    {
        mpp[s]=i;
    }
    else
    {
        ds.unionbyrank(i,mpp[s]);
    }
}
}
vector<vector<string>>vs(n);
for(auto it:mpp)
{
    string s1=it.first;
    int nod=it.second;
    int uup=ds.uparent(nod);
    
vs[uup].push_back(s1);
}
vector<vector<string>>ans;
for(int i=0;i<n;i++)
{
    if(vs[i].size()==0)
    continue;
    vector<string>temp;
    temp.push_back(accounts[i][0]);
    for(auto it:vs[i])
    {
temp.push_back(it);
    }
    ans.push_back(temp);
}
return ans;
    }
};