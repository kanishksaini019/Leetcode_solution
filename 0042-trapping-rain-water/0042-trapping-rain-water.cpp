class Solution {
public:
    int trap(vector<int>& height) {
       int l=0;
       int lmax=0;
       int n=height.size();
       int r=n-1;
       int rmax=0;
       int total=0;
       while(r>l)
       {
        if(height[r]>=height[l])
        {
            if(height[l]<lmax)
            {
                total+=lmax-height[l];
                l++;
            }
            else
            {
                lmax=height[l];
                l++;
            }
        }
        else
        {
            if(height[r]<rmax)
            {
                total+=rmax-height[r];
                r--;
            }
            else
            {
                rmax=height[r];
                r--;
            }
        }
       }
       return total; 
    }
};