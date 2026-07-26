class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        int len=0;
        int prevlen=0;
        int i=0;
   while(i<n)
   {
if(s[i]==' ')
{
i++;
if(len!=0)
prevlen=len;
len=0;
}
else if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z')
{
    len++;
    i++;
}
   }
   if(len==0)
   return prevlen;
   else return len;
        }
};