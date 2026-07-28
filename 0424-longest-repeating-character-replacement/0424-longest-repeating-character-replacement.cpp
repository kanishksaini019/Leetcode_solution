class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
      
        int r=0;
        int l=0;
        int maxfeq=0;
int maxlen=0;
    int hash[256]={0};
        while(r<n)
        {
           hash[s[r]-'A']++;
           maxfeq=max(maxfeq,hash[s[r]-'A']);
           if((r-l+1)-maxfeq>k)
           {
       hash[s[l]-'A']--;
       l++;
           }
           if((r-l+1)-maxfeq<=k)
           {
int len=r-l+1;
maxlen=max(maxlen,len);
           }
           r++;
        }
        return maxlen;
    }
};
           