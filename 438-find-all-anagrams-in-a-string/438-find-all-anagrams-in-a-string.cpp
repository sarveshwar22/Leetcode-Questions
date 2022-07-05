class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> cnt;
        unordered_map<char,int> cnt2;
        // for(int i=0;i<26;i++)
        // {
        //     cnt['a'+i]=0;
        //     cnt2['a'+i]=0;
        // }
        vector<int> ans;
        if(s.size()<p.size())
            return ans;
        for(int i=0;i<p.size();i++)
        {
            cnt[p[i]]++;
            cnt2[s[i]]++;
        }
        int start=0;
        int end=p.size()-1;
        // for(auto ele:cnt)
        //     cout<<ele.first<<" "<<ele.second<<endl;
        // cout<<endl;
        while(end<s.size())
        {
            if(cnt==cnt2)
                ans.push_back(start);
            
        // for(auto ele:cnt2)
        //     cout<<ele.first<<" "<<ele.second<<endl;
        //     cout<<endl;
            end++;
            if(end<s.size())
                cnt2[s[end]]++;
            cnt2[s[start]]--;
            if(cnt2[s[start]]==0)
                cnt2.erase(s[start]);
            start++;
        }
        return ans;
        
        
        
        
    }
};