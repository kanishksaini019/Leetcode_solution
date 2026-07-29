class Solution {
public:
    char findTheDifference(string s, string t) {
      unordered_map<char,int>mpp;
      int n=s.length();
      for(int i=0;i<n;i++)
      {
        mpp[s[i]]++;
      } 
      int m=t.length();
      char ans;
      for(int j=0;j<m;j++)
      {
        if(mpp[t[j]]>0)
        {
          
            mpp[t[j]]--;
              continue;
        }
        else
        {
           ans=t[j]; 
           break;
        }

      } 
      return ans;
    }
};