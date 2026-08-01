class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
  unordered_map<int,int>mpp;
  unordered_map<int,int>mpp2;
  bool flag=false;
  for(int i=0;i<n;i++)
  {
    if(mpp[nums[i]]>0)
    {
        if((i-mpp2[nums[i]])<=k)
        {
            flag=true;
            break;
        }
        else
        {
            mpp2[nums[i]]=i;
        }
    }
    mpp[nums[i]]++;
    mpp2[nums[i]]=i;
  }
  return flag;
    }
};
