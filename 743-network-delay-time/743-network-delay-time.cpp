class Solution {
    
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>>adj(n+1);
        int m=times.size();
        for(int i=0;i<m;i++)
        {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        
        while(!pq.empty())
        {
            auto curr=pq.top();
            pq.pop();
            for(auto it:adj[curr.second])
            {
                if(dist[it.first]>curr.first+it.second)
                    {dist[it.first]=curr.first+it.second;
                    pq.push({dist[it.first],it.first});
                }
            }
        }
        int ans=0;
        for(int i=1;i<n+1;i++)
        {
            if(dist[i]==INT_MAX)
                return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};