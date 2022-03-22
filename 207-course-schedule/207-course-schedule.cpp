class Solution {
    vector<vector<int>>adj;
    vector<bool> visited;
    vector<bool> visited2;
        
    bool isCyclic(int node)
    {
        if(!visited[node])
        {
            visited[node]=true;
            visited2[node]=true;
            for(auto neigh:adj[node])
            {
                if(!visited[neigh] && isCyclic(neigh) || visited2[neigh])
                    return true;
            }
        }
        visited2[node]=false;
        return false;
    }
        
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj.resize(numCourses);
        visited.resize(numCourses,false);
        visited2.resize(numCourses,false);
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        for(int i=0;i<numCourses;i++)
        {
            if(isCyclic(i))
                return false;
        }
        return true;
    }
};