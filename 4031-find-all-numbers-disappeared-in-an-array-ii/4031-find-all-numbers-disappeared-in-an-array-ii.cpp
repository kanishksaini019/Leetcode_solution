class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
    set<int>st;
    for(int i=0;i<n;i++)
    {
        if(nums[i]>=lower&&nums[i]<=upper)
        st.insert(nums[i]);
    }
     vector<int>arr;
    for(int i=lower;i<=upper;i++)
    {
      if(st.find(i)==st.end())
       arr.push_back(i);
    }
    vector<vector<int>>ans;
   
    int poi=0;
    while(poi<arr.size())
    {
        int temp=poi+1;
        while(temp<arr.size())
        {
            if(arr[temp-1]+1==arr[temp])
           temp++;
           else
           break;
    }
    ans.push_back({arr[poi],arr[temp-1]});
    poi=temp;
    }
    return ans;
    }
};