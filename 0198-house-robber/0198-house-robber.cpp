class Solution {
public:
int rob(vector<int>& nums,int sum,vector<int>& dp,int index)
{
if(index==0)
return dp[0]=nums[0];
if(index<0)
{
    return 0;
}
if(dp[index]!=-1)
return dp[index];


int left=nums[index]+rob(nums,sum,dp,index-2);

   int right=rob(nums,sum,dp,index-1);
return dp[index]=max(right,left);
}
    int rob(vector<int>& nums) {
      int n=nums.size();
      vector<int>dp(n+1,-1);
int sum=0;
   rob(nums,sum,dp,n-1); 
   return dp[n-1]; 
    }
};