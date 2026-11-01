class Solution {
public:
    int countCommas(int n) {
        if(n<1000)
        return 0;
       
      if(n>=1000&&n<10000)
      return  n-999;
      if(n>=10000&&n<100000)
      {
        int ans=9999-999;
        ans+=(n-9999);
        return ans;
      }
     return 99001;
return 0;
    }
};