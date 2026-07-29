class Solution {
public:
    bool isBalanced(string num) {
        int oddsum=0;
        int evensum=0;
        int n=num.length();
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            evensum+=(num[i]-'0');
            else
            oddsum+=(num[i]-'0');
        }
        if(evensum==oddsum)
        return true;
        else
        return false;
    }
};