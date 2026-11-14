class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
       int n=nums.size();
      long long k1=k;
    long long ogk=k;
       long long  op=0;
       for(int i=0;i<n;i++)
       {
if(nums[i]<=k1)
{
    k1=k1-nums[i];
    continue;
}
else
{
    long long q=(nums[i]-k1)/ogk;
    if(1LL*q*1LL*ogk+k1>=nums[i])
    {
       op+=q;
        k1+=1LL*ogk*q;
        k1-=nums[i];
    }
    else
    {
        op+=q+1;
        k1+=1LL*ogk*(q+1);
        k1-=nums[i];
    }
}
       }
     __int128 cost=(__int128)op*(op+1)/2;
return cost%1000000007;
    }
};