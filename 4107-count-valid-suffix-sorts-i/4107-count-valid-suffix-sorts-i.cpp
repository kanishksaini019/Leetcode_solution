class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
     int p=0;
     int n=nums.size();
     int i=n-1;
     while(i>0&&target[i-1]>=target[i])
     i--;
   int cnt=0;
  while(p<n){
    if(nums[p]==target[p])
    p++;
    else break;
  }
 int bad=0;
 vector<int>freq(1000001,0);
 
  for(int j=n-1;j>=i;j--)
  {
if(freq[nums[j]]==0) bad++;
 freq[nums[j]]++;
 if(freq[nums[j]]==0) bad--;

 if(freq[target[j]]==0) bad++;
 freq[target[j]]--;
 if(freq[target[j]]==0) bad--;
  if(bad==0&&j<=p)
  cnt++;
  }
  return cnt;
    }
};