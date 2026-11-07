class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        long long ans=0;
        int prev=-1;
        for(int i=0;i<requests.size();i++)
        {
if(prev==-1)
{
    ans+=requests[i];
    prev=requests[i];
}
else
{
    ans+=abs(requests[i]-prev);
    prev=requests[i];
}
        }
        return ans;
    }
};