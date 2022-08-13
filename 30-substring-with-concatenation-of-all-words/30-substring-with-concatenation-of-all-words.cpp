class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> v1;
        int n=words.size();
        int k=words[0].size();
        if(s.size()<n*k)
            return v1;
        unordered_map<string,int> m1;
        for(int i=0;i<n;i++)
            m1[words[i]]++;
        
        for(int i=0;i<=s.size()-n*k;i++)
        {
            int cnt=n;
            unordered_map<string,int>m2;
            int start=i;
            while(cnt)
            {
                string s1=s.substr(start,k);
                m2[s1]++;
                if(m1.find(s1)!=m1.end() && m1[s1]>=m2[s1])
                {
                    cnt--;
                    start+=k;
                }
                else
                    break;
            }
            if(!cnt)
            {
                v1.push_back(i);
            }
        
        }
        return v1;
    }
};