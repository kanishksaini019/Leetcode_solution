class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
     int n=ransomNote.length();
     int m=magazine.length();
     unordered_map<char,int>mpp;
     for(int i=0;i<m;i++)
     {
        mpp[magazine[i]]++;
     }
     bool flag=false;
     int i=0;
     for( i=0;i<n;i++)
     {
if(mpp[ransomNote[i]]>0)
{
    mpp[ransomNote[i]]--;
}
else
{
    flag=false;
    break;
}
     }
     if(i==n)
     {
    return true;
    }
    else
    {
        return false;
    }
    }
};