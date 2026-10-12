class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        vector<int>ans;
        int sleft=s;
        for(int i=2;i<=n;i++)
        { 
            bool pr=true;
            for(int j=2;j*j<=i;j++)
            {
                if(i%j==0)
                {
                    pr=false;
                    break;
                }
            }
         if(sleft>=i)
         {
             if(pr)
             {
                 ans.push_back(i);
                 sleft=sleft-i;
             }
         }
         else
         {
             break;
         }
        }
       return ans;
    }
};