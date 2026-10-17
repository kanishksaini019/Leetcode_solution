class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
     int s1=source[0];
     int s2=source[1];
     int t1=target[0];  
     int t2=target[1];
     int r1=(s1+s2)%2;
     int r2=(t1+t2)%2;
     if(r1!=r2)
     return -1;
     if(s1+s2==t1+t2)
     return 1;
     if(abs(s1-s2)==abs(t1-t2)&&t1-t2==0)
     return 1;
     if((s1-s2)==(t1-t2))
     return 1;
     else return 2;  
    }
};