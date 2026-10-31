class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
      int n=nums.size();
      vector<pair<int,int>>ans;
      for(int i=0;i<n;i++)
      {
        int mod=nums[i]%k;
ans.push_back({mod,nums[i]});
      }  
      int cnt=0;
      int prevmod=-1;
      int sum=0;
      int ans1=1;
   for(auto it:ans)
   {
    if(prevmod==-1)
    {
        prevmod=it.first;
        cnt++;
        sum+=it.first;
        continue;
    }
    if(prevmod==it.first)
    {
        cnt++;
        sum+=it.first;
        if(sum%k==prevmod)
        {
            ans1=max(ans1,cnt);
        }
    }
    else
    {
        cnt=1;
        sum=it.first;
        prevmod=it.first;
    }
   }
     if(sum%k==prevmod)
        {
            ans1=max(ans1,cnt);
        }
        return ans1;
    }
};