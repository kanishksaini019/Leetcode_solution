class Solution {
public:
    int countRotations(string s, int k) {
        int n=s.length();
        int ans=0;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            string curr;
            curr=s.substr(i+1,n);
            curr+=s.substr(0,i+1);
            cnt=0;
            for(int i=0;i<n-1;i++)
            {
                if(curr[i]==curr[i+1])
                {
cnt++;
                }
            }
            if(cnt==k)
            ans++;
        }
        return ans;
    }
};