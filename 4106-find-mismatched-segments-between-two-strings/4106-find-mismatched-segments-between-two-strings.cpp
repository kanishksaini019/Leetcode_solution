class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
  int n=min(s1.length(),s2.length()); 
  vector<vector<string>>ans;
  int i=0;
  while(i<n)
  {
   if(s1[i]==s2[i])
   {
    i++;
   continue;
   }
   string s3;
   string s4;
   int j;
   for( j=i;j<n;j++)
   {
    if(s1[j]!=s2[j])
    {
  s3.push_back(s1[j]);
  s4.push_back(s2[j]);
    }
    else 
    break;
   }
   i=j;
   ans.push_back({s3,s4});
  }
  if(i<s1.length() || i<s2.length())
{
 string  s3=s1.substr(i);
 string s4=s2.substr(i);
  ans.push_back({s3,s4});
}
  return ans;
    }
};