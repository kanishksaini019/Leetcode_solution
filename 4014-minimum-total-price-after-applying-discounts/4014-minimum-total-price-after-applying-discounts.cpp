class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int n=prices.size();
        int n1=discounts.size();
        sort(prices.begin(),prices.end());
        sort(discounts.begin(),discounts.end());
        int ptr1=n-1;
        int ptr2=n1-1;
    double sum=0;
        while(ptr2>=0&&ptr1>=0)
        {
        int d=discounts[ptr2];
        int p=prices[ptr1];
        double val=double((p*(100-d)))/(double)100;
      sum+=val;
        ptr1--;
        ptr2--;
        }
    while(ptr1>=0)
    {
        sum+=prices[ptr1];
        ptr1--;
    }
    return sum;
    }
};