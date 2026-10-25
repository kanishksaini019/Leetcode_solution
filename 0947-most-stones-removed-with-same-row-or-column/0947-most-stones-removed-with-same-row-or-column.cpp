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
    int removeStones(vector<vector<int>>& stones) {
       int maxrow=0;
       int maxcol=0;
       for(auto it:stones)
       {
        maxrow=max(maxrow,it[0]);
        maxcol=max(maxcol,it[1]);
       } 
       disjointset ds(maxrow+maxcol+2);
       unordered_map<int,int>mpp;
       for(auto it:stones){
        int noderow=it[0];
        int nodecol=it[1]+maxrow+1;
        ds.unionbyrank(noderow,nodecol);
        mpp[noderow]=1;
        mpp[nodecol]=1;
       }
       int cnt=0;
       for(auto it:mpp)
       {
        if(ds.uparent(it.first)==it.first)
        {
            cnt++;
        }
       }
       int n=stones.size();
       return n-cnt;
    }
};