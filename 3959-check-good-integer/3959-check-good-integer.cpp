class Solution {
public:
    bool checkGoodInteger(int n) {
        long long sum=0;
        long long ssum=0;
        while(n!=0)
        {
            int r=n%10;
            sum+=r;
            ssum+=r*r;
            n=n/10;
        }
        if(ssum-sum>=50)
        return true;
        else
        return false;
    }
};