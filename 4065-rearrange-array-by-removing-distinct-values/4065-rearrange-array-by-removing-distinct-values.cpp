class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>taken(n,0);
       sort(nums.begin(),nums.end());
       vector<int>ans;
       int prev=-1;
       int ptr=0;
      while(ans.size()!=n)
      {
        if(prev!=nums[ptr]&&taken[ptr]==0)
        {
            ans.push_back(nums[ptr]);
            taken[ptr]=1;
            prev=nums[ptr];
            ptr++;
            
            if(ptr>=n)
            {
                prev=-1;
                ptr=0;
            }
        }
        else
        {
          ptr++;
          if(ptr>=n)
          {
            prev=-1;
            ptr=0;
          }  
        }
      }
      return ans;
    }
};