class Solution {
public:
 vector<int> twoSum(vector<int>& nums, int target)
   {
    int n=nums.size();
    int start=0;
    int end=n-1;
    int v1=0;
    int v2=0;
  for (int i=0;i<n;i++)
  {
    for (int j=i+1;j<n;j++)
    {
        if (nums[i]+nums[j]==target)
        {
         return{i,j};
        }
    }
  }
  return {};
   }
};