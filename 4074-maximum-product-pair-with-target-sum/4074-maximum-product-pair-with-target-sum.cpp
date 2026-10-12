class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>pa(2,-1);
        vector<int>max(2,-1);
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
           for(int j=0;j<n;j++)
           {
               if(nums[i]+nums[j]==target)
               {
                   if(nums[i]*nums[j]>maxi&&nums[i]!=nums[j]&&nums[i]>nums[j])
                   {
                       maxi=nums[i]*nums[j];
                       pa[0]=i;
                       pa[1]=j;
                   }
               }
           }
        }
        return pa;
    }
};