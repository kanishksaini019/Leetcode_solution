class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
       int p=1;
       unordered_map<int,int>mpp;
       int r=0;
       int l=0;
       int cnt=1;
       if(n==1&&nums[0]>k)
       {
        return 0;
       }
      
       while(r<n)
       {
mpp[r]=nums[r];
p=p*nums[r];
while(p>=k)
{
    p=p/mpp[l];
    l++;
}
cnt+=r-l+1;
r++;
       }
       cnt--;
       return cnt;
    }
};