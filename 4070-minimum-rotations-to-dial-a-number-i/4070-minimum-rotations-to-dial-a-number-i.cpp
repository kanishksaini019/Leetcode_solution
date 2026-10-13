class Solution {
public:
    int minRotations(string s) {
    int i=0;
    int n=s.length();
    int sum=0;
    int prevnumber=-1;
    int number;
    while(i<n)
    {
      number=s[i]-'0';
       if(i>0)prevnumber=s[i-1]-'0';
       else  prevnumber=-1;
       if(prevnumber==-1&&number==0)
       {
       
       i++;
       continue;
       }
       else if(prevnumber==-1&&number!=0)
       {
        i++;
         int path1=abs(number-0);
    int path2=abs(abs(number-0)-10);
    sum+=min(path1,path2);
        continue;
       }
      
        int path1=abs(number-prevnumber);
    int path2=abs(abs(number-prevnumber)-10);
    sum+=min(path1,path2);
    
    i++;
    }
    return sum;
    }
};