class Solution {
public:
    int findLHS(vector<int>& nums) {
     int n=nums.size();
  unordered_map<int,int>mpp;
  for(int i=0;i<n;i++)
  {
    mpp[nums[i]]++;
  }
  int maxlen=0;
  for(auto it:mpp)
  {
    if(mpp.count(it.first+1))
    {
        maxlen=max(maxlen,mpp[it.first]+mpp[it.first+1]);
    }
  }
  return maxlen;
    }
};