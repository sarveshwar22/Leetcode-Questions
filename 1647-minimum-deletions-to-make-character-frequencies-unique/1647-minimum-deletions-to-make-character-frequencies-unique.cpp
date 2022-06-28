class Solution {
public:
    int minDeletions(string s) {
        unordered_set<int> st;
        unordered_map<char,int> m;
        
        for(int i=0;i<s.size();i++) m[s[i]]++;
        
        int ans=0;
        for(auto x:m)
        {
           while(st.find(x.second)!=st.end())
             {
                    x.second--;
                    ans++;
              }
            if(x.second!=0)
            st.insert(x.second); 
        }
        return ans;
    }
};