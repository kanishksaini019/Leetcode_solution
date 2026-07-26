class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
     int i=0;
     int j=n-1;
     bool flag=true;
     while(i<=j)
     {
      if((s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z')&&(s[j]>='a'&&s[j]<='z'||s[j]>='A'&&s[j]<='Z')||(s[i]>='0'&&s[i]<='9')&&(s[j]>='0'&&s[j]<='9'))
      {
        if(toupper(s[i])==toupper(s[j])){
        i++;
j--;
        }
        else
        {
            flag=false;
            break;
        }
      } 
      else if((s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z')&&(s[j]>='0'&&s[j]<='9'))
      {
        flag =false;
        break;
      }
       else if((s[j]>='a'&&s[j]<='z'||s[j]>='A'&&s[j]<='Z')&&(s[i]>='0'&&s[i]<='9'))
      {
        flag =false;
        break;
      }
      else if(!((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9')))
      {
i++;
      }
      else if(!((s[j]>='a'&&s[j]<='z')||(s[j]>='A'&&s[j]<='Z')||(s[j]>='0'&&s[j]<='9')))
      {
        j--;
      }
     }
    return flag;    
    }
};