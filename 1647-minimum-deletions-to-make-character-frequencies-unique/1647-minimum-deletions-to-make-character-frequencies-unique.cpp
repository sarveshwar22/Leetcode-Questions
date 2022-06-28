class Solution {
public:
    int minDeletions(string s) {
        map <char,int> count;
        for (auto &c: s) count[c]++;
        map <int,int> mp;
        int mmax=0;
        for (auto p: count){ 
            mp[p.second]++;
            mmax=max(mmax,p.second);
        }
        deque <int> dq;
        int ans=0;
        int i=1;
        while (i<=mmax){
            
            if (mp[i]==0) {
                dq.push_back(i);
                i++;
                continue;
            }
            if (mp[i]==1) {
                i++;
                continue;
            }
            
            while (!dq.empty() && mp[i]>1){
                int val=dq.back();
                dq.pop_back();
                ans+=i-val;
                mp[i]--;
            }
            if (mp[i]>1) ans+=(mp[i]-1)*i;
            i++;
        }
        return ans;
    }
};