class Solution {
public:
    int maxDistance(string moves) {
  int hor=0;
  int vert=0;
  int cnt=0;
  for(int i=0;i<moves.size();i++)
  {
 if(moves[i]=='U')
  vert++;
 if(moves[i]=='D')
  vert--;
 if(moves[i]=='R')
  hor++;
 if(moves[i]=='L')
  hor--;
  if(moves[i]=='_')
  {
   cnt++;
  }
  }      
  return abs(vert)+abs(hor)+cnt;
    }
};