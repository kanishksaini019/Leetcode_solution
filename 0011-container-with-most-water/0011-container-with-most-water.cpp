class Solution {
public:
    int maxArea(vector<int>& height) {
     int lp=0;
     int rp=height.size()-1;
     int maxw=0;
     while(rp>lp)
     {
        int w=rp-lp;
        int h=min(height[rp],height[lp]);
        int area=h*w;
        maxw=max(maxw,area);
        if (height[rp]>height[lp])
        {
            lp++;
        }
        else 
        {
            rp--;
        }
       
     }
      return maxw;   
        
    } };