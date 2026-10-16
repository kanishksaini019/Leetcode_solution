class Solution {
public:
string binary(int n)
{
    string s="";
    while(n!=0)
    {
        int q=n%2;
        s+=to_string(q);
        n=n/2;
    }
        while(s.length()<8)
        {
            s+='0';
        }
    reverse(s.begin(),s.end());
    return s;
}
    bool isPalindromic(string s) {
        string ans="";
       for(int i=0;i<s.length();i++)
       {
      ans+=binary((int)s[i]);
       }
       int i=0;
       int j=ans.length()-1;
       bool palindrome=true;
       while(j>=i)
       {
        if(ans[i]==ans[j])
{
    i++;
    j--;
}
else
{
    palindrome=false;
    break;
}
       }
       if(palindrome)
       return true;
       else  return false;
    }
};