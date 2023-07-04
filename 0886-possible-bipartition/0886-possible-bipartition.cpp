class Solution {
    bool bfs(int i, vector<vector<int>>& adj, vector<int>& visited)
    {
        queue<int> q;
        q.push(i);
        visited[i] = 1;
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            for(int neigh:adj[front])
            {
                if(visited[neigh]==0){
                    visited[neigh] = visited[front]==1?2:1;
                    q.push(neigh);
                }
                else if(visited[front]==visited[neigh])
                    return false;
                
            }
        }
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n);
        vector<int> visited(n,0);
        for(vector<int>& d:dislikes)
        {
            adj[d[0]-1].push_back(d[1]-1);
            adj[d[1]-1].push_back(d[0]-1);
        }
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                if(!bfs(i,adj,visited))
                    return false;
            } 
        }
        return true;
    }
};