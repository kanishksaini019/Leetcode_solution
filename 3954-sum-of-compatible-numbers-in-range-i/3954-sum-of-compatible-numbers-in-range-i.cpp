class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
       int mum=n*k;
       long long sum=0;
       for(int i=1;i<=mum+1;i++)
       {
        if(abs(n-i)<=k&&(n&i)==0)
        {
            sum+=i;
        }
       } 
       return sum;
    }
};