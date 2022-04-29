class Solution {
    bool dfs(vector<vector<int>>& graph,int node,vector<int>& visited,int color)
    {
        if(visited[node])
        {
            return visited[node]==color;
        }
        visited[node]=color;
        for(auto neigh:graph[node])
        {
            if(!dfs(graph,neigh,visited,-1*color))
                return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n,0);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                if(!dfs(graph,i,visited,1))
                    return false;
            }
        }
        return true;
    }
};