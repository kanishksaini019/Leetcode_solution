class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();
        map<int,vector<int>>adj;
        map<int,int>mpp;
        for(int i=0;i<n;i++)
        {
            adj[nums[i]].push_back(i);
            mpp[nums[i]]++;
        }
        int cnt=0;
        for(auto it:mpp)
        {
            if(it.second>=3)
            {
                bool oo=true;
                int prediff=-1;
                int prev=-1;
                for(auto pp:adj[it.first])
                {
              if(prev!=-1)
{
    int diff=pp-prev;

    if(prediff!=-1 && prediff!=diff)
    {
        oo=false;
        break;
    }

    prediff=diff;
}
prev=pp;
                }
                if(oo==true)
                cnt++;
            }
        }
        return cnt; 
    }
};