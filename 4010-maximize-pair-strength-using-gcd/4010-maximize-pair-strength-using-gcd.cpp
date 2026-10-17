class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
            long long p=(long long)nums[i]*(long long)nums[j];
            long long g=gcd(nums[i],nums[j]);
            ans=max(ans,p/(g*g));
            }
        }
        return ans;
    }
};