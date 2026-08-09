class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
     vector<int>st;
     int n=asteroids.size();
     
     for(int i=0;i<n;i++)
     {
        while(!st.empty()&&st.back()>0&&asteroids[i]<0)
        {
            if(st.back()<-asteroids[i])
            {
                st.pop_back();
            }
            else if(st.back()==-asteroids[i])
            {
            st.pop_back();
            asteroids[i]=0;
            break;
            }
            else 
            {
        asteroids[i]=0;
        break;
        }
     }
     if(asteroids[i]!=0)
     st.push_back(asteroids[i]);
     }
     return st;
    }
};