class Solution {
public:
    bool threeFibonacciSum(int n) {
    int t1=0;
        int t2=1;
        while(t1+t2+(t1+t2)<n)
        {
            int t3=t1+t2;
            t1=t2;
            t2=t3;
        }
        return t1+t2+t1+t2==n;
    }
};