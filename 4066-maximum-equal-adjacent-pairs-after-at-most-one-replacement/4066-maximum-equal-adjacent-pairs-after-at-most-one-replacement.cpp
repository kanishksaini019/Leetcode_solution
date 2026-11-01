class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
 
       map<pair<int,int>,int>mpp;
       for(int i=0;i<n-1;i++)
       {
        if(nums[i]==nums[i+1])
        cnt++;
        else
        {
            int a=min(nums[i],nums[i+1]);
            int b=max(nums[i],nums[i+1]);
            mpp[{a,b}]++;
        }
       }
       int n1=mpp.size();
   int freq=0;
   for(auto it:mpp)
   {
    if(it.second>freq)
    freq=it.second;
   }
       return cnt+freq;
    }
};