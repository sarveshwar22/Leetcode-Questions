class Solution {
    int n;
    bool dfs(vector<vector<int>>& graph, int i, vector<int>& visited)
    {
        if(visited[i])
            return visited[i]==1?true:false;
        visited[i]=-1;
        for(int neigh:graph[i])
        {
            if(!dfs(graph,neigh,visited))
                return false;
        }
        
        visited[i] = 1;
            
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        n = graph.size();
        vector<int> res;
        vector<int> visited(n,0);
        for(int i=0;i<n;i++)
        {
            if(dfs(graph,i,visited))
                res.push_back(i);
        }
        return res;
    }
};