class Solution {
public:
    string longestPrefix(string s) {
       int n=s.length();
    vector<int>z(n,0);
    int r=0;
    int l=0;
    for(int i=1;i<n;i++)
    {
        if(r<i)
        {
            r=i;
            l=i;
            while(r<n&&s[r-l]==s[r])
        {
            r++;
        }
        z[i]=r-l;
        r--;
        }
        else
        {
          int k=i-l;
          if(z[k]<r-i+1)
          {
            z[i]=z[k];
          }
          else
          {
            l=i;
            while(r+1<n&&s[r-l+1]==s[r+1])
            {
                r++;
            }
            z[i]=r-l+1;
          }
        }
    }
    int len=0;
    for(int i=0;i<n;i++)
    {
        if(z[i]+i==n)
        {
 if(i+z[i]==n)
        len=max(len,z[i]);
        }
    }
    return s.substr(0,len);    
     
    }
};