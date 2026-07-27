class Solution {
public:
    string multiply(string num1, string num2) {
        int n=num1.length();
        int m=num2.length();
        if(n==0||m==0)
        return "0";
        int mul=0;
        int p1=0;
        int p2=0;
        vector<int>ans(n+m,0);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
        int mul=(num1[i]-'0')*(num2[j]-'0');
        p1=i+j+1;
        p2=i+j;
        int sum=mul+ans[p1];
        ans[p1]=sum%10;
        ans[p2]+=sum/10;
            }
        }string res="";
     for(int x:ans)
     {
        if(!(res.empty()&&x==0))
   res.push_back(x+'0');
     }
     if(res.empty())
     return "0";
     return res;
    }
};