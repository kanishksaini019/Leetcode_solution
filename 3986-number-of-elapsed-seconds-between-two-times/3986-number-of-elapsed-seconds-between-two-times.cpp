class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
       int sh=0;
       int eh=0;
       int sm=0;
       int em=0;
       int ss=0;
       int es=0; 
       sh=stoi(startTime.substr(0,2));
       eh=stoi(endTime.substr(0,2));
       sm=stoi(startTime.substr(3,2));
       em=stoi(endTime.substr(3,2));
       ss=stoi(startTime.substr(6,2));
       es=stoi(endTime.substr(6,2));
   int time1=sh*60*60+sm*60+ss;
   int time2=eh*60*60+em*60+es;
   int time=time2-time1;
       return time;

    }
};