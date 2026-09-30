class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       unordered_set<string>st;
       int n=wordList.size();
       queue<pair<string,int>>q;
       q.push({beginWord,1});
        for(int i=0;i<n;i++)
        {
            st.insert(wordList[i]);
        } 
        st.erase(beginWord);
        while(!q.empty())
        {
            auto p=q.front().first;
            auto p1=q.front().second;
            q.pop();
            if(p==endWord)
            return p1;
            for(int i=0;i<p.length();i++)
            {
                char original=p[i];
                for(char ch='a';ch<='z';ch++)
                {
                    p[i]=ch;
                    if(st.find(p)!=st.end())
                    {
                        st.erase(p);
                        q.push({p,p1+1});
                    }
                }
                p[i]=original;
            }
        }
        return 0;
    }
};