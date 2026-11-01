class Solution {
public:
int fromfront(int a,int b)
{
    if(a<=b)
    return b-a;
    else return a-b;
}
int back(int a,int b)
{
   return 10-abs(a-b);
}
    int minRotations(int n, string s) {
        vector<int>comp(n);
        int tot=0;
        for(int i=0;i<n-1;i++)
        {
            int a=s[i]-'0';
            int b=s[i+1]-'0';
            comp[i]=min(fromfront(a,b),back(a,b));
            tot+=comp[i];
        }
        int pre=min(fromfront(0,s[0]-'0'),back(0,s[0]-'0'));
        tot+=min(fromfront(0,s[0]-'0'),back(0,s[0]-'0'));
        int ans=tot;
        int cop=tot;

        for(int i=0;i<n-1;i++)
        {
          int a=s[n-1]-'0';
          int b=s[i]-'0';
          int pre1=min(fromfront(a,b),back(a,b));
           cop-=comp[i];
           cop+=pre1;
           ans=min(ans,cop);
           cop=tot; 
        }
        cop-=pre;
        int seq=min(fromfront(s[n-1]-'0',0),back(s[n-1]-'0',0));
        cop+=seq;
        ans=min(ans,cop);
        return ans;
    }
};