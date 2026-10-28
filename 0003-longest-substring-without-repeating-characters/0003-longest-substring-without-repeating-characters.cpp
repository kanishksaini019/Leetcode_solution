class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int r=0;
        int l=0;
    vector<int> hash(256, -1);
        int maxlen=0;
while(r<n)
{
    if(hash[s[r]]!=-1)
    {
        l=max(l,hash[s[r]]+1);
    }
maxlen=max(maxlen,r-l+1);
hash[s[r]]=r;
r++;
}
return maxlen;
    }
};