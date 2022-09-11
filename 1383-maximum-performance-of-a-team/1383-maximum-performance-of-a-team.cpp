class Solution {
    int mod = 1e9+7;
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> candidates(n);
        for(int i=0;i<n;i++)
            candidates[i]={efficiency[i],speed[i]};
        sort(candidates.rbegin(),candidates.rend());
        long speedsum=0;
        long res=0;
        
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(auto& [e,s]:candidates)
        {
            pq.push(s);
            speedsum+=s;
            if(pq.size()>k)
            {
                speedsum-=pq.top();
                pq.pop();
                
            }
            res=max(res,speedsum*e);
        }
        return res%mod;
    }
};