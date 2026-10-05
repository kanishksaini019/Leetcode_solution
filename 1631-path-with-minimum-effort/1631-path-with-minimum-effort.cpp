class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
    int n=heights.size();
    int m=heights[0].size();
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
vector<vector<int>>dist(n,vector<int>(m,1e9));
pq.push({0,{0,0}});
dist[0][0]=0;
int delrow[]={-1,0,1,0};
int delcol[]={0,1,0,-1};
while(!pq.empty())
{
int r=pq.top().second.first;
int c=pq.top().second.second;
int dista=pq.top().first;
pq.pop();
if(r==n-1&&c==m-1)
return dista;
for(int k=0;k<4;k++)
{
    int nr=delrow[k]+r;
    int nc=delcol[k]+c;
    if(nr>=0&&nr<n&&nc>=0&&nc<m)
    {
        int diffra=max((abs(heights[nr][nc]-heights[r][c])),dista);
        if(diffra<dist[nr][nc])
        {
            dist[nr][nc]=diffra;
            pq.push({diffra,{nr,nc}});
        }
    }
}

}
return 0;
    }
};