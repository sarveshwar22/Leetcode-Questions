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
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n,0);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                if(!bfs(i,graph,visited))
                    return false;
            } 
        }
        return true;
    }
};