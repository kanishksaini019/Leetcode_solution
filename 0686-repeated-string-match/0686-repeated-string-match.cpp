class Solution {
public:
bool check(string text,string pattern)
{
    int n=text.length();
    int m=pattern.length();
    if(m>n)
    return false;
int phas=0;
int thas=0;
int q=256;
int p=101;
int h=1;
bool ans=false;
for(int i=0;i<m-1;i++)
{
h=(h*q)%p;
}
for(int i=0;i<m;i++)
{
thas=(thas*q+text[i])%p;
phas=(phas*q+pattern[i])%p;
}
for(int i=0;i<=n-m;i++)
{
    if(phas==thas)
    {
        bool flag=true;
     for(int j=0;j<m;j++)
     {
        if(text[i+j]!=pattern[j])
        {
            flag=false;
            break;
        }
     }
     ans=flag;
    }
     if(ans)
     {
        ans=true;
        break;
     }
     else if(i<n-m)
     {
        thas=(thas-h*text[i])%p;
        if(thas<0)
        thas+=p;
        thas=thas*q;
        thas=thas+text[i+m];
        thas=thas%p;
     }
    }
return ans;
}
    int repeatedStringMatch(string a, string b) {
   int n=a.length();
   int m=b.length();
   int cnt=0;
   if(m%n==0)
   cnt=m/n;
   else
   cnt=m/n+1;
  string temp=a;
  for(int i=0;i<cnt-1;i++)
  {
    temp+=a;
  }
  if(check(temp,b))
  return cnt;
   else if(check(temp+a,b))
  return cnt+1;
  return -1;
    }
};