class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
       unordered_map<int,int>mpp;
       vector<vector<int>>adj(103);
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        mpp[nums[i]]++;
        adj[nums[i]].push_back(i);

    }
int cnt=0;
for(auto it:mpp)
{
    if(it.second==3)
    {
int first=adj[it.first][0];
int second=adj[it.first][1];
int third=adj[it.first][2];
if(second-first==third-second)
cnt++;
    }
}
    return cnt; 
    }  
};