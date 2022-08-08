class Solution {
    vector<bool> visited;
    void dfs(vector<vector<int>>& adj,int node,long long& count)
    {
        visited[node]=true;
        count++;
        for(auto& child:adj[node])
        {
            if(!visited[child])
            dfs(adj,child,count);
        }
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& e:edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        long long ans=((long long)n*(n-1))/2;
        visited = vector<bool>(n,false);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                long long count=0;
                dfs(adj,i,count);
                ans-=(count*(count-1))/2;
            }
        }
        return ans;
        
    }
};