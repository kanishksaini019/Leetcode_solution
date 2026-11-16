class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long sum=0;
        sort(nums.begin(),nums.end(),greater<int>());
        
    for(int i=0;i<k;i++)
    {
    if(mul==0)
    sum+=nums[i];
    else
    {
        sum+=1LL*nums[i]*mul;
        mul=mul-1;
    } 
    }
    return sum;
    }
};