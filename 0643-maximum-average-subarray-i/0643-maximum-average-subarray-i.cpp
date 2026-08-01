class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
      double avg=0.0;
      double maxi=INT_MIN;
 long long sum=0;
 for(long long  i=0;i<k;i++)
 {
    sum+=nums[i];
 }
 int l=0;
 int n=nums.size();
 for(int i=k;i<n;i++)
 {
avg=(double)sum/double(k);
maxi=max(maxi,avg);
sum=sum-nums[l];
sum=sum+nums[i];
l++;
 }
 avg = (double)sum /(double) k;
maxi = max(maxi, avg);
 return maxi;
    }
};