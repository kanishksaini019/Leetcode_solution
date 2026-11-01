class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
     int n=nums.size();
     vector<int>comp(n/2);
     int p=0;
     for(int i=0;i<n;i+=2)
     {
        comp[p]=stoi(to_string(nums[i])+to_string(nums[i+1]));
        p++;
     }  
     int ans=INT_MAX; 
     for(int i=0;i<n/2;i++)
     {
ans=min(ans,comp[i]);
    
     }
     return ans;
    }

};