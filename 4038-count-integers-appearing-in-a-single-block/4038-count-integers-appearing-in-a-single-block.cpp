class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        unordered_map<int,int>mpp;
         unordered_map<int,int>mpp1;
        for(int i=0;i<n;i++)
        {
            mpp[nums[i]]++;
            if(mpp[nums[i]]==1)
            {
                mpp1[nums[i]]=i;
            }
        }
   for(auto it:mpp)
   {
    for(int i=mpp1[it.first];i<n;i++)
    {
        if(nums[i]==it.first)
        {
            mpp[nums[i]]--;
        }
        else
        {
            break;
        }
    }
    if(mpp[it.first]!=0)
    continue;
    else
    cnt++;
   }
   return cnt;
  
    }
};