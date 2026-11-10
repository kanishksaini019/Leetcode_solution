class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
      int sum1=start[0]+start[1];
int sum2=target[0]+target[1];
if(sum1%2==sum2%2)
return true;
else
return false;
    }
};