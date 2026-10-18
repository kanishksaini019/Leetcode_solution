class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        q.push({0,0});
        bool going=true;
        vis[0][0]=1;
        int ar=-1;
        int ac=-1;
       
        while(going)
        {
        int r=q.front().first;
            int c=q.front().second;
            q.pop();
            ar=r;
            ac=c;
                if(grid[r][c]=='R')
                {
                    if(r>=0&&r<m&&c+1>=0&&c+1<n&&vis[r][c+1]==0){
                q.push({r,c+1});
                        vis[r][c+1]=1;
                    }
                    else
                    going=false;
                }
                else if(grid[r][c]=='U')
                 {
             
 if(r-1>=0&&r-1<m&&c>=0&&c<n&&vis[r-1][c]==0){
              q.push({r-1,c});
     vis[r-1][c]=1;
 }
                    else
                    going=false;
                 }
                else if(grid[r][c]=='L')
                {
                     if(r>=0&&r<m&&c-1>=0&&c-1<n&&vis[r][c-1]==0){
                q.push({r,c-1});
                         vis[r][c-1]=1;
                     }
else
                     going=false;

                }
              else   if(grid[r][c]=='D')
                 {
                      if(r+1>=0&&r+1<m&&c>=0&&c<n&&vis[r+1][c]==0){
                q.push({r+1,c});
                          vis[r+1][c]=1;
                      }
else
                      going=false;
                 }
            }
        vector<int>ans(2);
        ans[0]=ar;
        ans[1]=ac;
        return ans;
        
    }
};