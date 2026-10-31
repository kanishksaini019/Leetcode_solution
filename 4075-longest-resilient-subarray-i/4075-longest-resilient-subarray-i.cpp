class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
       int n=nums.size();
    int sum=0;
    int ans=1;
    int prevmod=-1;
for(int i=0;i<n;i++)
{sum=0;
prevmod=-1;
    for(int j=i;j<n;j++)
    {
        if(prevmod!=-1&&nums[j]%k!=prevmod)
        break;
        
        sum+=nums[j];
        if(sum%k==nums[j]%k)
        {
ans=max(ans,j-i+1);
        }
     
        prevmod=nums[j]%k;
    }
}
return ans;
    }
};