class Solution {
public:
    long long sumScores(string s) {
        int n=s.length();
        int r=0;
        int l=0;
        vector<int>z(n,0);
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
long long sum=n;
for(int i=1;i<n;i++)
{
    sum+=z[i];
}
return sum;
    }
};