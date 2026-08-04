class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
      int n =nums.size();
      int l=0;
      int r=0;
      int maxi=0;
     for(int i=0;i<n;i++)
     {
        l=i;
        int ma=0;
        for(int r=l;r<n;r++)
        {
            if(nums[l]%2!=0)
            {
                break;
            }
             if(nums[r]>threshold)
             {
            break;
             
             }
             else
             {
                ma=r-l+1;
             }
            if((r<n-1)&&nums[r]%2==nums[r+1]%2)
            {
                break;
            }
          ma=r-l+1;
        }
        maxi=max(ma,maxi);
     } 
     return maxi;
    }
};