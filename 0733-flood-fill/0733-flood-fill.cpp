class Solution {
public:
void dfs(vector<vector<int>>& image,vector<vector<int>>& ans,int inicolor,int color,int row,int col)
{
ans[row][col]=color;
int n=image.size();
int m=image[0].size();
for(int delrow=-1;delrow<=1;delrow++)
{
    for(int delcol=-1;delcol<=1;delcol++)
    {
        if(abs(delrow)==abs(delcol))
        continue;
        int roww=row+delrow;
        int coll=col+delcol;
        if(roww>=0&&roww<n&&coll>=0&&coll<m&&ans[roww][coll]!=color&&image[roww][coll]==inicolor)
        dfs(image,ans,inicolor,color,roww,coll);
    }
}
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor=image[sr][sc];
        vector<vector<int>>ans=image;
        dfs(image,ans,inicolor,color,sr,sc);
        return ans;
    }
};