class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int n=nums.size();
    vector<int>digi(n,0);int topi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int maxi=INT_MIN;
        int mini=INT_MAX;
    int n1=nums[i];
    while(n1!=0)
    {
        int r=n1%10;
        maxi=max(maxi,r);
        mini=min(mini,r);
        n1=n1/10;
    }
    digi[i]=maxi-mini;
    topi=max(topi,maxi-mini);
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(digi[i]==topi)
        {
ans+=nums[i];
        }
    }
    return ans;
    }
};