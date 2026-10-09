class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
  int u=source[0];
  int v=source[1];
  int u1=target[0];
  int v2=target[1];
  if(u==u1&&v==v2)
  {
return 0;
  }
  if(u+v==9&&u1+v2==9)
  {
return 1;
  } 
  if(abs(u-u1)==abs(v-v2))
  return 1;
  if(u==u1&&v==v2)
  {
return 0;
  }
  for(int delrow=-1;delrow<=1;delrow++)
  {
    for(int delcol=-1;delcol<=1;delcol++)
    {
        int nrow=delrow+u;
        int ncol=delcol+v;
        if(nrow==u1&&ncol==v2)
        return 1;
    }
  }  
  if(u==u1||v==v2)
  {
    return 1;
  }
  
  return 2;
    }
};